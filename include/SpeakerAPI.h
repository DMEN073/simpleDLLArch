#ifndef INCLUDE_SPEAKERAPI_H_
#define INCLUDE_SPEAKERAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

void* create_speaker();
void speaker_say(void* speaker);
void destroy_speaker(void* speaker);

#ifdef __cplusplus
}
#endif

#endif  // INCLUDE_SPEAKERAPI_H_