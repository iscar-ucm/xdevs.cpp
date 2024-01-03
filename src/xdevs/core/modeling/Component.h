/*
 * Copyright (C) 2016-2016 Jos� Luis Risco Mart�n <jlrisco@ucm.es>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see
 * http://www.gnu.org/licenses/
 *
 * Contributors:
 *  - Jos� Luis Risco Mart�n
 */

#ifndef SRC_XDEVS_CORE_MODELING_COMPONENT_H_
#define SRC_XDEVS_CORE_MODELING_COMPONENT_H_

#include "Port.h"
#include <list>
#include <vector>
#include <string>

class Component {
protected:
	std::string name;
	std::list<PortPtr> inPorts;
	std::list<PortPtr> outPorts;
public:
	Component(const std::string& name);
	virtual ~Component();
	const std::string getName();

	virtual void initialize() = 0;
	virtual void exit() = 0;
	virtual bool isInputEmpty();
	virtual void addInPort(PortPtr port);
	virtual const std::list<PortPtr>& getInPorts();
	virtual void addOutPort(PortPtr port);
	virtual const std::list<PortPtr>& getOutPorts();
	//virtual const std::string& toString();
};

#endif /* SRC_XDEVS_CORE_MODELING_COMPONENT_H_ */
