#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T> struct Observer {
  virtual void field_changed(T &source, const string &field_name) = 0;
};

template <typename T> struct Observable {
  void notify(T &source, const string &field_name) {
    for (auto observer : m_observers)
      observer->field_changed(source, field_name);
  }
  void subscribe(Observer<T> &observer) { m_observers.push_back(&observer); }
  void unsubscribe(Observer<T> &observer) {
    m_observers.erase(remove(m_observers.begin(), m_observers.end(), &observer),
                      m_observers.end());
  }

private:
  vector<Observer<T> *> m_observers;
};

struct Person
    : Observable<Person> { // Observable
                           // <<<<-------------------------------------
  void set_age(uint8_t age) {
    auto old_can_vote = get_can_vote();
    this->m_age = age;
    notify(*this, "age");

    if (old_can_vote != get_can_vote())
      notify(*this, "can_vote");
  }
  uint8_t get_age() const { return m_age; }
  bool get_can_vote() const { return m_age >= 16; }

private:
  uint8_t m_age{0};
};

struct TrafficAdministration
    : Observer<Person> { // Observer <<<<-----------------------
  void field_changed(Person &source, const string &field_name) {
    if (field_name == "age") {
      if (source.get_age() < 17)
        cout << "Not old enough to drive!\n";
      else {
        cout << "Mature enough to drive!\n";
        source.unsubscribe(*this);
      }
    }
  }
};

int main() {
  Person p;
  TrafficAdministration ta;
  p.subscribe(ta);
  p.set_age(16);
  p.set_age(17);
  return EXIT_SUCCESS;
}
