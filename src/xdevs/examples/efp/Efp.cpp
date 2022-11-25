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

#include "Efp.h"

Efp::Efp(const std::string& name, const double& generatorPeriod, const double& processorPeriod, const double& transducerPeriod)
		: Coupled(name),
		  ef("ef", generatorPeriod, transducerPeriod),
		  processor("processor", processorPeriod) {
	Coupled::addComponent(&ef);
	Coupled::addComponent(&processor);
	Coupled::addCoupling(&ef, &ef.oOut, &processor, &processor.iIn);
	Coupled::addCoupling(&processor, &processor.oOut, &ef, &ef.iIn);
}

Efp::~Efp() {
	// TODO Auto-generated destructor stub
}

