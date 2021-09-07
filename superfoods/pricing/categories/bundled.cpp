#include "./bundled.hpp"
#include <map>
#include <string>
#include <algorithm>

namespace superfoods::pricing::categories {

  Bundled::Bundled(std::list<Product> const& products, double bundledPrice)
    : products(products), bundledPrice(bundledPrice) {}
  
  double Bundled::calculatePrice(Basket const& basket) const {
    ProductMap productMap {};
    int bundledCount {};

    for (auto const & product : this->products) {
      productMap[product.getName()] = basket.getProductCountByName(product.getName());
    }

    if (!this->isBundled(productMap)) {
      return this->calculateTotalAsSimple(productMap);
    }

    bundledCount = this->getBundledCount(productMap);

    return bundledCount * bundledPrice + this->calculateTotalAsSimple(productMap, bundledCount);
  }

  bool Bundled::isBundled(ProductMap& productMap) const {
    for (auto const & product : this->products) {
      if (productMap[product.getName()] < 1) return false;
    }
    return true;
  }

  double Bundled::calculateTotalAsSimple(ProductMap& productMap, int bundledCount) const {
    double total = 0.0;
    for (auto const & product : this->products) {
      total += product.getTotal(productMap[product.getName()] - bundledCount);
    }
    return total;
  }

  int Bundled::getBundledCount(ProductMap const& productMap) const {
    return std::min_element(productMap.cbegin(), productMap.cend(), 
      [](auto const& left, auto const& right) {
        return left.second < right.second;
    })->second;
  }

}