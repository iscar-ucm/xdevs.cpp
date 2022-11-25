#include "Light.h"

const char* Light::TypeAsString[] = { "RED", "GREEN", "YELLOW" };


Light::Light(const std::string& name, Light::Type type, int period) : Atomic(name),
                                                                      period(period),
                                                                      iIn("in"),
                                                                      oOut("out") {
  this->type = type;
  this->addInPort(&iIn);
  this->addOutPort(&oOut);
}

Light::~Light() {}

void Light::initialize() {
  this->clock = 0.0;
  Atomic::passivate();
}

void Light::exit() {}

void Light::deltint() {
  this->clock += this->getSigma();
  Atomic::passivate();
}

void Light::deltext(double e) {
  this->clock += e;
  if(!iIn.isEmpty()) {
    std::cout << "CLOCK: " << clock << " s - " << TypeAsString[type] << " for " << period << " seconds." << std::endl;
    Atomic::holdIn(TypeAsString[type], period);
  }
}

void Light::lambda() {
  auto event = std::make_shared<Integer>(1);
  oOut.addValue(event);
}
