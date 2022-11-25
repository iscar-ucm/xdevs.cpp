#ifndef SRC_XDEVS_EXAMPLES_TRAFFIC_GENERATOR_H_
#define SRC_XDEVS_EXAMPLES_TRAFFIC_GENERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Integer.h"
#include "../../core/modeling/Port.h"
#include "../../core/modeling/Atomic.h"
#include "../../core/modeling/Event.h"

class Generator : public Atomic {
public:
  Port oOut;

  Generator(const std::string& name);
  virtual ~Generator();

  virtual void initialize();
  virtual void exit();
  virtual void deltint();
  virtual void deltext(double e);
  virtual void lambda();
};

#endif
