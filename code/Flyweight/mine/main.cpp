#include "ConcreteFlyweight.h"
#include "Flyweight.h"
#include "FlyweightFactory.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  FlyweightFactory factory;
  Flyweight *fw = factory.getFlyweight("one");
  fw->operation();

  Flyweight *fw2 = factory.getFlyweight("two");
  fw2->operation();
  // aready exist in pool
  Flyweight *fw3 = factory.getFlyweight("one");
  fw3->operation();
  return 0;
}
