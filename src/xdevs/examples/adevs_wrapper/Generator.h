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

#ifndef SRC_XDEVS_EXAMPLES_EFP_GENERATOR_H_
#define SRC_XDEVS_EXAMPLES_EFP_GENERATOR_H_

#include "../../core/modeling/Port.h"
#include "../../core/modeling/Atomic.h"
#include "../../core/modeling/Event.h"
#include "Job.h"
#include <iostream>
#include <string>

class Generator : public Atomic {
protected:
	int jobCounter;
	double period;
public:
	Port iStop;
	Port oOut;

	Generator(const std::string& name, const double& period);
	virtual ~Generator();

	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();
};

#endif /* SRC_XDEVS_CORE_TEST_EFP_GENERATOR_H_ */
