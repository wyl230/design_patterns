#pragma once
#include <memory>
class Product {

public:
  Product();
  virtual ~Product();

  virtual void use();
};

using product_ptr = std::shared_ptr<Product>;
