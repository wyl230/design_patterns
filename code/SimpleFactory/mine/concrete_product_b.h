
#pragma once
#include "product.h"

class ConcreteProductB : public Product {

public:
  ConcreteProductB();
  virtual ~ConcreteProductB();

  virtual void Use();
};
