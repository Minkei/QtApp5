# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appQtApp5_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appQtApp5_autogen.dir\\ParseCache.txt"
  "appQtApp5_autogen"
  )
endif()
