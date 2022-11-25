#ifndef SRC_XDEVS_EXAMPLES_TRAFFIC_LIGHT_H_
#define SRC_XDEVS_EXAMPLES_TRAFFIC_LIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Integer.h"
#include "../../core/modeling/Port.h"
#include "../../core/modeling/Atomic.h"
#include "../../core/modeling/Event.h"
#include "../../core/simulation/SimulationClock.h"

class Light : public Atomic {
  static const char* TypeAsString[];
public:
  enum Type {RED, GREEN, YELLOW};
  Port iIn;
  Port oOut;
  
  Light(const std::string& name, Light::Type type, int time);
  virtual ~Light();

  virtual void initialize();
  virtual void exit();
  virtual void deltint();
  virtual void deltext(double e);
  virtual void lambda();
protected:
  Light::Type type;
  int period;
  double clock;
};

#endif
