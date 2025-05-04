# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\tacticalMonsters_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tacticalMonsters_autogen.dir\\ParseCache.txt"
  "tacticalMonsters_autogen"
  )
endif()
