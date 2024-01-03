/*
 * Copyright (C) 2016-2016 José Luis Risco Martín <jlrisco@ucm.es>.
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
 *  - José Luis Risco Martén
 */

#ifndef SRC_XDEVS_CORE_MODELING_COUPLING_H_
#define SRC_XDEVS_CORE_MODELING_COUPLING_H_

#include <string>
#include "Port.h"

class Coupling {
protected:
  PortPtr portFrom;
  PortPtr portTo;
public:
  Coupling(PortPtr portFrom, PortPtr portTo);
  virtual ~Coupling();
  // Coupling members
  void propagateValues();
  PortPtr getPortFrom() const;
  PortPtr getPortTo() const;
  //std::string toString();
};

#endif /* SRC_XDEVS_CORE_MODELING_COUPLING_H_ */
