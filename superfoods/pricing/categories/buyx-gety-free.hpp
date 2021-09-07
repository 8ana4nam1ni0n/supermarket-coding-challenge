#pragma once

#include "./pricing-category.hpp"
#include "../../basket.hpp"
#include "../../product.hpp"

namespace superfoods::pricing::categories {

  class BuyXGetYFree : public PricingCategory {
    public:

      BuyXGetYFree(Product const&, int, int);

      double calculatePrice(Basket const &) const override;

    private:
      Product product;
      int xQuantity;
      int yQuantity;

      int filterNonFreeProducts(int amount) const;
  };
  
}