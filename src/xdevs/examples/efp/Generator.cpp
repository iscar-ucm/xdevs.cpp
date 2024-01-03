/*
 * Generator.cpp
 *
 *  Created on: 5 de may. de 2016
 *      Author: jlrisco
 */

#include "Generator.h"

Generator::Generator(const std::string& name, const double& period) : Atomic(name), jobCounter(1), period(period) {
  this->iStop = makePort("stop");
  this->oOut = makePort("out");
  this->addInPort(iStop);
  this->addOutPort(oOut);
}

Generator::~Generator() {
}

void Generator::initialize() {
  jobCounter = 1;
  this->holdIn("active", period);
}

void Generator::exit() {
}

void Generator::deltint() {
  jobCounter++;
  this->holdIn("active", period);
}

void Generator::deltext(double e) {
  this->passivate();
}

void Generator::lambda() {
  auto job = std::make_shared<Job>(std::to_string(jobCounter));
  oOut->addValue(job);
}
