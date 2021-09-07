#include <list>
#include <memory>
#include <cassert>
#include "./superfoods/checkout.hpp"
#include "./superfoods/pricing/categories/buyx-gety-free.hpp"
#include "./superfoods/pricing/categories/additional-taxes.hpp"
#include "./superfoods/pricing/categories/bundled.hpp"
#include "./superfoods/pricing/categories/simple.hpp"
#include "./superfoods/pricing/categories/pricing-category.hpp"

using namespace superfoods::pricing::categories;

std::list<std::shared_ptr<PricingCategory>> initPricingCategories();

constexpr int BUY2 = 2;
constexpr int GET_1_FREE = 1;

int main() {

  std::list<std::shared_ptr<PricingCategory>> categories = initPricingCategories();
  superfoods::pricing::PricingScheme scheme;

  for (auto const& category : categories) {
    scheme.addPricingCategory(category);
  }

  superfoods::Checkout c(scheme);

  c.scan("1983");
  c.scan("4900");
  c.scan("8873");
  c.scan("6732");
  c.scan("0923");
  c.scan("1983");
  c.scan("1983");
  c.scan("1983");
  int total = c.getTotal();
  assert(3037 == total);

  return 0;
}

std::list<std::shared_ptr<PricingCategory>> initPricingCategories() {
  return std::list<std::shared_ptr<PricingCategory>> {
    std::make_shared<BuyXGetYFree>(BuyXGetYFree(superfoods::Product("toothbrush", 1.99), BUY2, GET_1_FREE)),
    std::make_shared<Simple>(Simple(superfoods::Product("milk", 2.49))),
    std::make_shared<AdditionalTaxes>(AdditionalTaxes(superfoods::Product("wine", 15.49), 9.25 / 100)),
    std::make_shared<Bundled>(Bundled(std::list<superfoods::Product> { 
        { superfoods::Product("chips", 2.49) },
        { superfoods::Product("salsa", 3.49) }
      }, 4.99))
  };
}