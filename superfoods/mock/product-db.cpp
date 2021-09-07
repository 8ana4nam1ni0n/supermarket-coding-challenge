#include "product-db.hpp"

namespace superfoods::mock {

  using superfoods::Product;

  MockProductDB::MockProductDB() {
    this->itemsInStock = {
      { "1983", Product("toothbrush", 1.99) },
      { "4900", Product("salsa", 3.49) },
      { "8873", Product("milk", 2.49) },
      { "6732", Product("chips", 2.49) },
      { "0923", Product("wine", 15.49) }
    };
  }

  Product const& MockProductDB::getProductByCode(std::string const& code) {
    return this->itemsInStock[code];
  }

}