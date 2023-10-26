
#include <iostream>
#include <memory>
#include <string>

// 中介者接口
class Mediator {
public:
  virtual void mediate(std::string message, class Colleague *colleague) = 0;
};

// 同事类
class Colleague {
protected:
  std::shared_ptr<Mediator> mediator;

public:
  Colleague(std::shared_ptr<Mediator> m) : mediator(m) {}
  virtual void send(std::string message) = 0;
  virtual void receive(std::string message) = 0;
};

class ConcreteColleagueA : public Colleague {
public:
  ConcreteColleagueA(std::shared_ptr<Mediator> m) : Colleague(m) {}

  void send(std::string message) override {
    std::cout << "Colleague A sends: " << message << std::endl;
    mediator->mediate(message, this);
  }

  void receive(std::string message) override {
    std::cout << "Colleague A receives: " << message << std::endl;
  }
};

class ConcreteColleagueB : public Colleague {
public:
  ConcreteColleagueB(std::shared_ptr<Mediator> m) : Colleague(m) {}

  void send(std::string message) override {
    std::cout << "Colleague B sends: " << message << std::endl;
    mediator->mediate(message, this);
  }

  void receive(std::string message) override {
    std::cout << "Colleague B receives: " << message << std::endl;
  }
};

// 具体中介者
class ConcreteMediator : public Mediator {
private:
  std::shared_ptr<Colleague> colleagueA;
  std::shared_ptr<Colleague> colleagueB;

public:
  void setColleagueA(std::shared_ptr<Colleague> colleague) {
    colleagueA = colleague;
  }

  void setColleagueB(std::shared_ptr<Colleague> colleague) {
    colleagueB = colleague;
  }

  void mediate(std::string message, Colleague *colleague) override {
    if (colleague == colleagueA.get()) {
      colleagueB->receive(message);
    } else {
      colleagueA->receive(message);
    }
  }
};

int main() {
  auto mediator = std::make_shared<ConcreteMediator>();
  auto colleagueA = std::make_shared<ConcreteColleagueA>(mediator);
  auto colleagueB = std::make_shared<ConcreteColleagueB>(mediator);

  mediator->setColleagueA(colleagueA);
  mediator->setColleagueB(colleagueB);

  colleagueA->send("Hello from Colleague A");
  colleagueB->send("Hi from Colleague B");

  return 0;
}
