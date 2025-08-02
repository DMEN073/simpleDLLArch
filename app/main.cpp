// main.cpp
#include "ISpeaker.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
using LibHandle = HMODULE;
#define LOAD_LIB(name) LoadLibraryA(name)
#define LIB_PREFIX ""
#define LOAD_FUNC GetProcAddress
#define CLOSE_LIB FreeLibrary
#define LIB_EXTENSION ".dll"
#else
#include <dlfcn.h>
using LibHandle = void*;
#define LOAD_LIB(name) dlopen(name, RTLD_LAZY)
#define LOAD_FUNC dlsym
#define CLOSE_LIB dlclose
#define LIB_PREFIX "lib"
#define SHARED_LIB_PATH "../include/lib/"
#define LIB_EXTENSION ".so"
#endif

LibHandle loadLibraryByName(const char* libName) {
  std::string fullPath = std::string(SHARED_LIB_PATH) + LIB_PREFIX + libName + LIB_EXTENSION;
  return LOAD_LIB(fullPath.c_str());
}

int main() {
  //   LibHandle lib = loadLibraryByName("english");  // or "english.dll" on Windows
  auto lib = dlopen("/home/kaiping/code/simpleDLLArchi/lib/libenglish.so", RTLD_NOW | RTLD_GLOBAL);
  if (!lib) {
    std::cerr << "Failed to load library." << std::endl;
    return 1;
  }

  auto create = (void* (*)())LOAD_FUNC(lib, "create_speaker");
  auto say = (void (*)(void*))LOAD_FUNC(lib, "speaker_say");
  auto destroy = (void (*)(void*))LOAD_FUNC(lib, "destroy_speaker");

  if (!create || !destroy || !say) {
    std::cerr << "Failed to get function." << std::endl;
    CLOSE_LIB(lib);
    return 1;
  }

  void* speaker = create();
  say(speaker);
  destroy(speaker);

  CLOSE_LIB(lib);
  return 0;
}
