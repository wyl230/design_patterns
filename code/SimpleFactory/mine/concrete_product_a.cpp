

#include "concrete_product_a.h"
#include "print.hpp"
#include <iostream>
#include <string>

using namespace std;

ConcreteProductA::ConcreteProductA() { print("ConcreteProductA"); }

ConcreteProductA::~ConcreteProductA() { print("~ConcreteProductA"); }

void ConcreteProductA::Use() { cout << "use productA" << endl; }
