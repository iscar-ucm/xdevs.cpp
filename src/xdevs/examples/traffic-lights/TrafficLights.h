
#ifndef SRC_XDEVS_EXAMPLES_TRAFFIC_H_
#define SRC_XDEVS_EXAMPLES_TRAFFIC_H_

#include "../../core/modeling/Coupled.h"
#include "Generator.h"
#include "Light.h"

class TrafficLights : public Coupled {
protected:
  Generator generator;
  Light redLight;
  Light greenLight;
  Light yellowLight;

public:
  TrafficLights(const std::string& name);
  virtual ~TrafficLights();
};

#endif
