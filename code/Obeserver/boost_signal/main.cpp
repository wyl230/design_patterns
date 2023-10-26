#include <boost/signals2.hpp>
#include <iostream>
#include <string>
using namespace std;

template <typename T> struct Observable {
  void subscribe(const auto &&observer) { m_field_changed.connect(observer); }
  void unsubscribe(const auto &&observer) {
    m_field_changed.disconnect(observer);
  }

protected:
  boost::signals2::signal<void(T &, const string &)> m_field_changed;
};

struct Person
    : Observable<Person> { // Observable
                           // <<<<-------------------------------------
  void set_age(uint8_t age) {
    this->m_age = age;
    m_field_changed(*this, "age");
  }
  auto get_age() const { return m_age; }

private:
  uint32_t m_age{0};
};

struct TrafficAdministration { // Observer <<<<-----------------------
  static void field_changed(Person &source, const string &field_name) {
    if (field_name == "age") {
      if (source.get_age() < 17)
        cout << "Not old enough to drive!\n";
      else {
        cout << "Mature enough to drive!\n";
        source.unsubscribe(TrafficAdministration::field_changed);
      }
    }
  }
};

int main() {
  Person p;
  p.subscribe(TrafficAdministration::field_changed);
  p.set_age(16);
  p.set_age(20);
  return EXIT_SUCCESS;
}
