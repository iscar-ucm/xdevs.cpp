#include "Generator.h"

Generator::Generator(const std::string& name) : Atomic(name), oOut("out") {
  this->addOutPort(&oOut);
}

Generator::~Generator() {
}

void Generator::initialize() {
  Atomic::holdIn("active", 0.0);
}

void Generator::exit() {
}

void Generator::deltint() {
  Atomic::passivate();
}

void Generator::deltext(double e) {
  Atomic::passivate();
}

void Generator::lambda() {
  auto event = std::make_shared<Integer>(1);
  oOut.addValue(event);
}
