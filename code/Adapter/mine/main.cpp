//
// Adaptee（被适配者）和Adapter（适配器）是两个常见的设计模式中的概念，通常用于软件工程中，特别是在面向对象编程中。它们用于解决不同接口之间的兼容性问题，使不兼容的接口能够一起工作。
//
// Adaptee（被适配者）：
//
// Adaptee
// 是一个已经存在的类或接口，通常具有一些特定的功能或行为，但其接口与系统的要求不兼容。
// Adaptee 通常是需要被适配的旧组件或第三方库的一部分。
// Adaptee
// 定义了系统的功能，但其接口与系统的其他部分不匹配，因此需要适配器来使其与其他部分协同工作。
// Adapter（适配器）：
//
// Adapter 是一个中间层，它实现了目标接口，同时包装了 Adaptee
// 的功能，使其能够与目标接口兼容。 适配器通过将 Adaptee
// 的方法调用转换为目标接口的方法调用来实现适配。
// 适配器模式使不同接口的对象能够互相合作，而不需要修改它们的原始代码。
// 适配器可以是类适配器（继承）或对象适配器（组合）。类适配器使用继承，而对象适配器使用组合来实现适配。
// 适配器模式的典型应用是在将现有类或库集成到新的系统中时，通过适配器来实现接口的兼容性，而不需要修改已有的代码。这可以帮助减少代码的修改量，提高代码的可维护性，并允许不同部分的代码协同工作。
//
// 总结：Adaptee 是需要被适配的现有组件，而 Adapter 是用于使 Adaptee
// 与目标接口兼容的中间层。 Adapter 通过转换接口调用来连接 Adaptee
// 和目标接口，从而使它们可以一起工作。
#include "Adaptee.h"
#include "Adapter.h"
#include "Target.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Adaptee *adaptee = new Adaptee();
  Target *tar = new Adapter(adaptee);
  tar->request();

  return 0;
}
