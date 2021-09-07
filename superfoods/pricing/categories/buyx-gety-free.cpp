#include "./buyx-gety-free.hpp"
#include <algorithm>

namespace superfoods::pricing::categories {

  BuyXGetYFree::BuyXGetYFree(Product const & product, int xQuantity, int yQuantity)
    : product(product), xQuantity(xQuantity), yQuantity(yQuantity) {}

  double BuyXGetYFree::calculatePrice(Basket const & basket) const {
    return this->product.getTotal(
      this->filterNonFreeProducts(
        basket.getProductCountByName(this->product.getName())
      )
    );
  }

  int BuyXGetYFree::filterNonFreeProducts(int amount) const {
    // r is the remainder of the amount / the sum of xQuantity + yQuantity
    // This is used to check how many products will be in offer
    int r = amount % (this->xQuantity + this->yQuantity);
    int productsInOffer = (amount - r) / (this->xQuantity + this->yQuantity);
    productsInOffer = productsInOffer * this->yQuantity;
    productsInOffer += std::max(0, r - this->xQuantity);

    return amount - productsInOffer;
  }

}