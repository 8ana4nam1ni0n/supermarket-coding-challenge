#pragma once

#include <memory>
#include "./categories/pricing-category.hpp"

namespace superfoods::pricing {

  using pricing::categories::PricingCategory;

  class PricingScheme {
    public:
      PricingScheme();

      std::list<std::shared_ptr<PricingCategory>> const& getCategories() const;

      void addPricingCategory(std::shared_ptr<PricingCategory> const&);

    private:
      std::list<std::shared_ptr<PricingCategory>> categories;
  };

}