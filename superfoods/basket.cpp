#include "./basket.hpp"

namespace superfoods {

  Basket::Basket() = default;

  void Basket::add(Product const& product) {
    this->products.push_back(product);
  }

  int Basket::getProductCountByName(std::string const& name) const {
    int count = 0;
    for (auto const & product : this->products) {
      if (product.getName() == name) {
        count++;
      }
    }
    return count;
  }
}