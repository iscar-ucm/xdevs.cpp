#include "Integer.h"

Integer::Integer(const int& value) : value(value) { }

Integer::Integer(const Integer& src) : value(src.value) {}

const Integer& Integer::operator=(const Integer& right) {
  this->value = right.value;
  return *(this);
}


Integer::~Integer() { }

void Integer::setValue(const int& value) {
  this->value = value;
}

const int& Integer::getValue() const { return value; }
