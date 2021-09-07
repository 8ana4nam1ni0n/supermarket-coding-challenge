#pragma once

#include "./pricing-category.hpp"
#include "../../basket.hpp"
#include "../../product.hpp"

namespace superfoods::pricing::categories {

  class Simple : public PricingCategory {
    public:

      Simple(Product const&);

      double calculatePrice(Basket const&) const override;

    private:
      Product product;
  };
  
}