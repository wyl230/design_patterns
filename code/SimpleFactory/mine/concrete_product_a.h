#pragma once

#include "print.hpp"
#include "product.h"

class ConcreteProductA : public Product {

public:
  ConcreteProductA();
  virtual ~ConcreteProductA();

  virtual void Use();
};
