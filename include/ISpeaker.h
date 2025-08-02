#ifndef INCLUDE_ISPEAKER_H_
#define INCLUDE_ISPEAKER_H_

class ISpeaker {
 public:
  virtual ~ISpeaker() {};
  virtual void saySomething() = 0;
};

// extern "C" ISpeaker *createSpeaker();
// extern "C" void destroySpeaker(ISpeaker *pISpeaker);

#endif  // INCLUDE_ISPEAKER_H_