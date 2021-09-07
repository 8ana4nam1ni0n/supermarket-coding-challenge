#include "./simple.hpp"

namespace superfoods::pricing::categories {

  Simple::Simple(Product const & product): product(product) {}

  double Simple::calculatePrice(Basket const & basket) const {
    return this->product.getTotal(
      basket.getProductCountByName(this->product.getName())
    );
  }

}