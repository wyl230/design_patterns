#include <iomanip>
#include <iostream>
#include <memory>
#include <string_view>
#include <vector>

// mediator.hpp
struct Transmitter;
struct Receiver;
using Receiver_wp = std::weak_ptr<Receiver>;
struct Mediator {
  std::vector<Receiver_wp> receivers{};
  Transmitter *transmitter{nullptr};

  void accept(std::string_view msg);
};

// transmitter.hpp
struct Transmitter {
  std::shared_ptr<Mediator> mediator;
  Transmitter(decltype(mediator) m) : mediator(m) {
    mediator->transmitter = this;
  }

  void send(std::string_view msg) { mediator->accept(msg); }
};

// receiver.hpp
struct Receiver : public std::enable_shared_from_this<Receiver> {
  std::shared_ptr<Mediator> mediator;
  Receiver(decltype(mediator) m) : mediator(m) {
    std::cout << " created" << std::endl;
    // mediator->receivers.push_back(shared_from_this());
  }

  void accept(std::string_view msg) {
    std::cout << this << " received: " << std::quoted(msg) << std::endl;
  }
};

// mediator.cpp
void Mediator::accept(std::string_view msg) {
  for (auto r : receivers) {
    if (auto p = r.lock()) {
      p->accept(msg);
    }
  }
}

// main.cpp
int main() {
  auto mediator = std::make_shared<Mediator>();

  auto t = std::make_unique<Transmitter>(mediator);

  auto r1 = std::make_shared<Receiver>(mediator);
  mediator->receivers.push_back(r1);
  // auto r2 = std::make_shared<Receiver>(mediator);
  // auto r3 = std::make_shared<Receiver>(mediator);

  // auto r4 = std::move(r3);
  // r2.reset();

  t->send("hello world");
}
