#include "./pricing-scheme.hpp"

namespace superfoods::pricing {

  PricingScheme::PricingScheme() = default;

  std::list<std::shared_ptr<PricingCategory>> const& PricingScheme::getCategories() const {
    return this->categories;
  }

  void PricingScheme::addPricingCategory(std::shared_ptr<PricingCategory> const& category) {
    return this->categories.push_back(category);
  }

}