#pragma once

#include "product.h"
#include <memory>
#include <string>
using namespace std;

class Factory {

public:
  Factory();
  virtual ~Factory();

  static product_ptr createProduct(string proname);
};
