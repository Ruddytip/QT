# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Lesson_1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Lesson_1_autogen.dir\\ParseCache.txt"
  "Lesson_1_autogen"
  )
endif()
