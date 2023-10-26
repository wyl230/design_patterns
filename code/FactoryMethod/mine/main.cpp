#include "ConcreteFactory.h"
#include "Factory.h"
#include "Product.h"
#include <iostream>
using namespace std;

int main(int, char *[]) {
  Factory *fc = new ConcreteFactory();
  Product *prod = fc->factoryMethod();
  prod->use();

  delete fc;
  delete prod;

  return 0;
}
