#pragma once

#include <string>

namespace superfoods {

  class Product {
    public:
      Product() = default;
      Product(std::string const&, double);

      std::string const& getName() const;

      double getTotal(int) const;
      double getPrice() const;

    private:
      std::string name;
      double price;
  };

}