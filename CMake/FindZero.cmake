
find_package(RUBY REQUIRED)
if(RUBY_FOUND)
	message(STATUS "Ruby ${RUBY_VERSION} Found")
	#include_directories(${RUBY_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} ${RUBY_LIBRARY})
endif()

find_path(ZERO_INCLUDE_DIR Zero.h
  PATH_SUFFIXES Include
  PATHS
  Include/
  Zero/Include/
  ${ZERODIR}
  $ENV{ZERODIR})

find_library(ZERO_LIBRARY_DEBUG
  NAMES Zero
  PATH_SUFFIXES lib64 lib Debug
  PATHS
  Build/
  Build/Debug/
  build/
  build/debug/
  bin/
  lib/
  ${ZERODIR}
  $ENV{ZERODIR})

if(ZERO_LIBRARY_DEBUG)
  # Library found
  set(ZERO_FOUND TRUE)

  if(ZERO_LIBRARY_DEBUG)
    set(ZERO_LIBRARY ${ZERO_LIBRARY_DEBUG})
  endif()
  
else()
  set(ZERO_FOUND FALSE)
endif()

if(ZERO_FOUND)
  set(ZERO_LIBRARIES ${ZERO_LIBRARY})
else(ZERO_FOUND)
  set(ZERO_LIBRARIES)
endif(ZERO_FOUND)

mark_as_advanced(ZERO_INCLUDE_DIR
  ZERO_LIBRARY
  ZERO_LIBRARY_DEBUG)
