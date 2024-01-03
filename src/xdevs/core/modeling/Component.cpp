/*
 * Component.cpp
 *
 *  Created on: 5 de may. de 2016
 *      Author: jlrisco
 */

#include "Component.h"

Component::Component(const std::string& name) : name(name), inPorts(), outPorts() {}

Component::~Component() {}

bool Component::isInputEmpty() {
	std::list<PortPtr>::iterator itr;
	for(itr = inPorts.begin(); itr != inPorts.end(); ++itr) {
		PortPtr port = *itr;
		if(!port->isEmpty()) {
			return false;
		}
	}
	return true;
}

void Component::addInPort(PortPtr port) {
	inPorts.push_back(port);
}

const std::list<PortPtr>& Component::getInPorts() {
	return inPorts;
}

const std::string Component::getName() {
	return name;
}

void Component::addOutPort(PortPtr port) {
	outPorts.push_back(port);
}

const std::list<PortPtr>& Component::getOutPorts() {
	return outPorts;
}

/*const std::string& Component::toString(){
	std::string sb;
	sb << name << " : Inports[ ";
	std::list<const Port*>::iterator itr;
	for(itr = inPorts.begin(); itr != inPorts.end(); ++itr) {
		Port* port = *itr;
		sb << port->getName() << " ";
	}
	sb << "] Outports[ ";
	for(itr = outPorts.end(); itr != outPorts.end(); ++itr) {
		Port* port = *itr;
		sb << port->getName() << " ";
	}
	sb << "]";
	return sb;
}*/
