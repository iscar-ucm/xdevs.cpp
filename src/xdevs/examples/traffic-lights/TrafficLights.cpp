#include "TrafficLights.h"

TrafficLights::TrafficLights(const std::string& name)
  : Coupled(name),
    generator("generator"),
    redLight("redLight", Light::RED, 60),
    greenLight("greenLight", Light::GREEN, 57),
    yellowLight("yellowLight", Light::YELLOW, 3) {

  Coupled::addComponent(&generator);
  Coupled::addComponent(&greenLight);
  Coupled::addComponent(&yellowLight);
  Coupled::addComponent(&redLight);

  Coupled::addCoupling(&generator, &generator.oOut, &redLight, &redLight.iIn);
  Coupled::addCoupling(&redLight, &redLight.oOut, &greenLight, &greenLight.iIn);
  Coupled::addCoupling(&greenLight, &greenLight.oOut, &yellowLight, &yellowLight.iIn);
  Coupled::addCoupling(&yellowLight, &yellowLight.oOut, &redLight, &redLight.iIn);
}

TrafficLights::~TrafficLights() { }
