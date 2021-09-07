#pragma once

#include "./pricing-category.hpp"
#include "../../product.hpp"
#include "../../basket.hpp"

namespace superfoods::pricing::categories {

  class AdditionalTaxes : public PricingCategory {
    public:
      AdditionalTaxes(Product const& product, double tax);
      double calculatePrice(Basket const& basket) const override;

    private:
      Product product;
      double tax;

      double calculatePriceWithTax() const;
  };

}