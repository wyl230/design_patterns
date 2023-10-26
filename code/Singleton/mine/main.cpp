#include "Singleton.h"
#include <iostream>
using namespace std;

int main(int, char *[]) {
  Singleton *sg = Singleton::getInstance();
  sg->singletonOperation();

  return 0;
}
