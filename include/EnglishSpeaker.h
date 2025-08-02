#ifndef INCLUDE_ENGLISHSPEAKER_H_
#define INCLUDE_ENGLISHSPEAKER_H_

#include "ISpeaker.h"

class EnglishSpeaker : public ISpeaker {
 public:
  void saySomething() override;
};

#endif  // INCLUDE_ENGLISHSPEAKER_H_
