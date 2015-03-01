# - Find Zero
# Find the native Box2D includes and libraries
#
#  BOX2D_INCLUDE_DIR - where to find TmxParser/Config.hpp, etc.
#  BOX2D_LIBRARIES   - List of libraries when using libTmxParser.
#  BOX2D_FOUND       - True if libTmxParser found.

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

# Handle the QUIETLY and REQUIRED arguments and set SNDFILE_FOUND to TRUE if
# all listed variables are TRUE.
#include(FindPackageHandleStandardArgs)
#find_package_handle_standard_args(ZERO DEFAULT_MSG ZERO_LIBRARY ZERO_INCLUDE_DIR)

if(ZERO_FOUND)
  set(ZERO_LIBRARIES ${ZERO_LIBRARY})
else(ZERO_FOUND)
  set(ZERO_LIBRARIES)
endif(ZERO_FOUND)

mark_as_advanced(ZERO_INCLUDE_DIR
  ZERO_LIBRARY
  ZERO_LIBRARY_DEBUG)
