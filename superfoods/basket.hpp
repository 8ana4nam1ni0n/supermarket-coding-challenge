#pragma once

#include <list>
#include "./product.hpp"

namespace superfoods {

  class Basket {
    public:
      Basket();

      void add(Product const&);
      int getProductCountByName(std::string const&) const;

    private:
      std::list<Product> products;
  };

}