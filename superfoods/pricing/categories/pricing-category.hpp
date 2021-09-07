#pragma once
#include <memory>
#include "../../basket.hpp"

namespace superfoods::pricing::categories {

  struct PricingCategory {
    virtual double calculatePrice(Basket const&) const = 0;
  };

}