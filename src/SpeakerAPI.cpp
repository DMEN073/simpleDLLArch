// english_api.cpp
#include "SpeakerAPI.h"
#include "EnglishSpeaker.h"

extern "C" {

void* create_speaker() {
  return new EnglishSpeaker();
}

void speaker_say(void* speaker) {
  static_cast<EnglishSpeaker*>(speaker)->saySomething();
}

void destroy_speaker(void* speaker) {
  delete static_cast<EnglishSpeaker*>(speaker);
}
}
