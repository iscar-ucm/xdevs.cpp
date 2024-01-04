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

#ifndef SRC_XDEVS_EXAMPLES_EFP_TRANSDUCER_H_
#define SRC_XDEVS_EXAMPLES_EFP_TRANSDUCER_H_

#include <list>
#include <string>
#include <iostream>
#include "../../core/modeling/Port.h"
#include "../../core/modeling/Atomic.h"
#include "Job.h"

class Transducer : public Atomic {
protected:
	std::list<Event> jobsArrived;
	std::list<Event> jobsSolved;
	double observationTime;
	double totalTa;
	double clock;
public:
	Port iArrived;
	Port iSolved;
	Port oOut;

	Transducer(const std::string& name, double observationTime);
	virtual ~Transducer();

	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();
};

#endif /* SRC_XDEVS_CORE_TEST_EFP_TRANSDUCER_H_ */
