#include "DevStoneAtomic.h"
#include <iostream>

long DevStoneAtomic::NUM_DELT_INTS(0);
long DevStoneAtomic::NUM_DELT_EXTS(0);
long DevStoneAtomic::NUM_EVENT_EXTS(0);

DevStoneAtomic::DevStoneAtomic(const std::string& name, double preparationTime, double intDelayTime, double extDelayTime)
	: Atomic(name),
	  preparationTime(preparationTime),
	  intDelayTime(intDelayTime),
	  extDelayTime(extDelayTime),
	  dhrystone(),
	  iIn("in"),
	  oOut("out") {
	Component::addInPort(&iIn);
	Component::addOutPort(&oOut);
}

DevStoneAtomic::~DevStoneAtomic() {}

void DevStoneAtomic::initialize() {
	Atomic::passivate();
}

void DevStoneAtomic::exit() {
}
		
/// Internal transition function
void DevStoneAtomic::deltint() {
	NUM_DELT_INTS++;
	if(intDelayTime>0) dhrystone.execute(intDelayTime);
	Atomic::passivate();
	//std::cout << this->name << " (di)" << std::endl;
}
	
/// External transition function
void DevStoneAtomic::deltext(double e) {
  NUM_DELT_EXTS++;
  if(extDelayTime>0) dhrystone.execute(extDelayTime);
  if(!iIn.isEmpty()) {
    NUM_EVENT_EXTS+= iIn.getValues().size();
  }
  Atomic::holdIn("active", preparationTime);
}
	

/// Output function.
void DevStoneAtomic::lambda() {
  Event event = std::make_shared<Long>(0L);
  oOut.addValue(event);
}
