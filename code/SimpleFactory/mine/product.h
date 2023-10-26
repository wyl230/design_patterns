#pragma once

#include <memory>
class Product {

public:
  Product();
  virtual ~Product();

  virtual void Use() = 0;
};

using product_ptr = std::unique_ptr<Product>;
