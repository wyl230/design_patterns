
///////////////////////////////////////////////////////////
//  Factory.cpp
//  Implementation of the Class Factory
//  Created on:      01-十月-2014 18:41:33
//  Original author: colin
///////////////////////////////////////////////////////////

#include "factory.h"
#include "concrete_product_a.h"
#include "concrete_product_b.h"
#include "product.h"
#include <memory>

Factory::Factory() {}

Factory::~Factory() {}

product_ptr Factory::createProduct(string proname) {

  if ("A" == proname) {
    return make_unique<ConcreteProductA>();
  } else if ("B" == proname) {
    return make_unique<ConcreteProductB>();
  }
  return nullptr;
}
