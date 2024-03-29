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

//#include "Gpt.h"
#include "Efp.h"
#include "../../core/simulation/Coordinator.h"

int main() {
	// Gpt gpt("gpt", 1, 100); // Gpt example
	Efp efp("efp", 1, 3, 100);
	Coordinator coordinator(&efp);
	coordinator.initialize();
	coordinator.simulate((long int)10000);
	coordinator.exit();
	return 0;
}

