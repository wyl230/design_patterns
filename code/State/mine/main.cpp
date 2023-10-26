#include "ConcreteStateA.h"
#include "ConcreteStateB.h"
#include "Context.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  char a = '0';
  if ('0' == a)
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  Context *c = new Context();
  for (int i = 0; i < 5; i++) {
    c->request();
  }

  delete c;
  return 0;
}
