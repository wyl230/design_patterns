

#include <iostream>
#include <memory>
#include <string>

class Colleague;

class Mediator {
public:
    virtual void mediate(std::string message, std::shared_ptr<Colleague> colleague) = 0;
};

class Colleague : public std::enable_shared_from_this<Colleague> {
protected:
    std::shared_ptr<Mediator> mediator;

public:
    Colleague(std::shared_ptr<Mediator> m) : mediator(m) {}

    void send(std::string message) {
        if (mediator) {
            mediator->mediate(message, shared_from_this());
        }
    }

    virtual void receive(std::string message) = 0;
};

class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(std::shared_ptr<Mediator> m) : Colleague(m) {}

    void receive(std::string message) override {
        std::cout << "Colleague A receives: " << message << std::endl;
    }
};

class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(std::shared_ptr<Mediator> m) : Colleague(m) {}

    void receive(std::string message) override {
        std::cout << "Colleague B receives: " << message << std::endl;
    }
};

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

    void mediate(std::string message, std::shared_ptr<Colleague> colleague) override {
        if (colleague == colleagueA) {
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
