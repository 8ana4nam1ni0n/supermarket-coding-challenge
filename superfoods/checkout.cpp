#include "checkout.hpp"
namespace superfoods {

  Checkout::Checkout(PricingScheme const& pricingScheme) 
    : pricingScheme(pricingScheme) {}

  void Checkout::scan(std::string const& code) {
    this->basket.add(this->productDB.getProductByCode(code));
  }

  int Checkout::getTotal() const {
    int total = 0;
    for (auto const& category : this->pricingScheme.getCategories()) {
      total += category->calculatePrice(this->basket) * 100; // get price in cents
    }
    return total;
  }
}