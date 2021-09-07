#include "product.hpp"

namespace superfoods {

  Product::Product(std::string const & name, double price)
    : name(name), price(price) {}
  
  std::string const & Product::getName() const {
    return this->name;
  }

  double Product::getTotal(int amount) const {
    return this->price * amount;
  }

  double Product::getPrice() const {
    return this->price;
  }

}