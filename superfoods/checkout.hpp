#pragma once
#include <string>
#include "./basket.hpp"
#include "./pricing/pricing-scheme.hpp"
#include "./mock/product-db.hpp"

// method scan will retrieve product from MockDB and will add it to basket
// method get total will send the basket to the scheme and the scheme will get the category
// finally the category will calculate the total
// TEST

namespace superfoods {

  using superfoods::pricing::PricingScheme;
  using superfoods::mock::MockProductDB;

  class Checkout {
    public:

      Checkout(PricingScheme const&);

      void scan(std::string const&);
      int getTotal() const;

    private:
      PricingScheme pricingScheme;
      Basket basket;
      MockProductDB productDB;

  };
}