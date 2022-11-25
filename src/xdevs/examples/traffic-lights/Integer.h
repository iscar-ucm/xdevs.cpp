#ifndef _INTEGER_H_
#define _INTEGER_H_

#include "../../core/modeling/Event.h"

class Integer : public BaseEvent {
protected:
  int value;
public:
  Integer(const int& value);
  Integer(const Integer& src);
  const Integer& operator=(const Integer& right);
  virtual ~Integer();

  void setValue(const int& value);
  const int& getValue() const;
};

#endif /* SRC_XDEVS_CORE_TEST_EFP_JOB_H_ */
