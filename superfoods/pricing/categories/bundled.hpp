#pragma once
#include <list>
#include <map>
#include "../../product.hpp"
#include "../../basket.hpp"
#include "./pricing-category.hpp"

namespace superfoods::pricing::categories {

  using ProductMap = std::map<std::string, int>;

  class Bundled : public PricingCategory {
    public:
      Bundled(std::list<Product> const&, double);
      double calculatePrice(Basket const&) const override;

    private:
      std::list<Product> products;
      double bundledPrice;

      bool isBundled(ProductMap &) const;
      double calculateTotalAsSimple(ProductMap &, int bundledCount = 0) const;
      int getBundledCount(ProductMap const&) const;

  };

}