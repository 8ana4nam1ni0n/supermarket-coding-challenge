#include "./additional-taxes.hpp"

namespace superfoods::pricing::categories {

  AdditionalTaxes::AdditionalTaxes(Product const & product, double tax)
    : product(product), tax(tax) {}
  
  double AdditionalTaxes::calculatePrice(Basket const & basket) const {
    int productCount = basket.getProductCountByName(this->product.getName());
    
    return productCount * this->calculatePriceWithTax();
  }

  double AdditionalTaxes::calculatePriceWithTax() const {
    return this->product.getPrice() * this->tax + this->product.getPrice();
  }

}