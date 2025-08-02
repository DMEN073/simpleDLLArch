# src/lib/CMakeLists.txt

# Define the MyLib library target
add_library(english SHARED EnglishSpeaker.cpp SpeakerAPI.cpp)

# Specify include directories for MyLib
target_include_directories(english PUBLIC ${PROJECT_SOURCE_DIR}/include)
