#include <iomanip>
#include <iostream>
#include <memory>
#include <set>
#include <string_view>

// mediator.hpp
struct Transmitter;
struct Receiver;
struct Mediator {
  std::set<Receiver *> receivers{};
  Transmitter *transmitter{nullptr};

  Mediator &operator+=(Receiver *r) {
    receivers.insert(r);
    return *this;
  }
  Mediator &operator-=(Receiver *r) {
    receivers.erase(r);
    return *this;
  }
  Mediator &operator+=(Transmitter *t) {
    transmitter = t;
    return *this;
  }
  Mediator &operator-=(Transmitter *t) {
    transmitter = nullptr;
    return *this;
  }

  void accept(std::string_view msg);
};

// transmitter.hpp
struct Transmitter {
  std::shared_ptr<Mediator> mediator;
  Transmitter(decltype(mediator) m) : mediator(m) { *mediator += this; }
  ~Transmitter() { *mediator -= this; }

  void send(std::string_view msg) { mediator->accept(msg); }
};

// receiver.hpp
struct Receiver {
  std::shared_ptr<Mediator> mediator;
  Receiver(decltype(mediator) m) : mediator(m) { *mediator += this; }
  ~Receiver() { *mediator -= this; }

  void accept(std::string_view msg) {
    std::cout << this << " received: " << std::quoted(msg) << std::endl;
  }
};

// mediator.cpp
void Mediator::accept(std::string_view msg) {
  for (auto r : receivers)
    r->accept(msg);
}

// main.cpp
int main() {
  auto mediator = std::make_shared<Mediator>();

  auto t = std::make_unique<Transmitter>(mediator);
  auto r1 = std::make_unique<Receiver>(mediator);
  auto r2 = std::make_unique<Receiver>(mediator);
  auto r3 = std::make_unique<Receiver>(mediator);

  r2.reset();

  t->send("hello world");
}
