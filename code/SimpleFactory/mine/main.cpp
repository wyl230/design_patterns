
#include "factory.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int, char *[]) {
  for (const auto &product_type : {"A", "B", "A"}) {
    product_ptr prod = Factory::createProduct(product_type);
    prod->Use();
  }

  return 0;
}
