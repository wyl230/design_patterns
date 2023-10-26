#include "Abstraction.h"
#include "ConcreteImplementorA.h"
#include "ConcreteImplementorB.h"
#include "RefinedAbstraction.h"
#include <iostream>

using namespace std;

int main(int, char *[]) {

  Implementor *pImp = new ConcreteImplementorA();
  Abstraction *pa = new RefinedAbstraction(pImp);
  pa->operation();

  Abstraction *pb = new RefinedAbstraction(new ConcreteImplementorB());
  pb->operation();

  delete pa;
  delete pb;

  return 0;
}
