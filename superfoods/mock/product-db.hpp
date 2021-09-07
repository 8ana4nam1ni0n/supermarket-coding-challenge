#pragma once

#include <map>
#include <string>

#include "../product.hpp"

namespace superfoods::mock {

  class MockProductDB {
    public:
      MockProductDB();

      Product const& getProductByCode(std::string const&);
    
    private:
      std::map<std::string, superfoods::Product> itemsInStock;
  };
  
}