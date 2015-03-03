cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME "Zero")
project(${PROJECT_NAME})

include_directories("Include")
include_directories("Dependencies/glm")
include_directories("Dependencies/rapidjson/include")
include_directories("Dependencies/ruby/usr/include/ruby-2.3.0")
include_directories("C:/ruby/include/ruby-2.3.0")

set(ROOT_HEADER_FILES
	"include/zero.h"
)

set(UTILITY_HEADER_FILES
	"include/utility/common.h"
)

set(UTILITY_FILE_HEADER_FILES
	"include/utility/file/file.h"
)

set(UTILITY_JSON_HEADER_FILES
	"include/utility/json/json.h"
)

set(UTILITY_RUBY_HEADER_FILES
	"include/utility/ruby/ruby.h"
)

set(UTILITY_RUBY_MODULE_HEADER_FILES
	"include/utility/ruby/modules/module.h"
	"include/utility/ruby/modules/class.h"
	"include/utility/ruby/modules/function.h"
	"include/utility/ruby/modules/zero.h"
)

set(RUBY_MODULE_TEST_HEADER_FILES
	"include/utility/ruby/modules/test/test.h"
)

set(HEADER_FILES
	${ROOT_HEADER_FILES}
	${UTILITY_HEADER_FILES}
	${UTILITY_FILE_HEADER_FILES}
	${UTILITY_JSON_HEADER_FILES}
	${UTILITY_RUBY_HEADER_FILES}
	${UTILITY_RUBY_MODULE_HEADER_FILES}
	${RUBY_MODULE_TEST_HEADER_FILES}
)

set(ROOT_SOURCE_FILES
	"source/zero.cpp"
)

set(UTILITY_FILE_SOURCE_FILES
	"source/utility/file/file.cpp"
)

set(UTILITY_JSON_SOURCE_FILES
	"source/utility/json/json.cpp"
)

set(UTILITY_RUBY_SOURCE_FILES
	"source/utility/ruby/ruby.cpp"
)

set(UTILITY_RUBY_MODULE_SOURCE_FILES
	"source/utility/ruby/modules/module.cpp"
	"source/utility/ruby/modules/class.cpp"
	"source/utility/ruby/modules/function.cpp"
	"source/utility/ruby/modules/zero.cpp"
)

set(RUBY_MODULE_TEST_SOURCE_FILES
	"source/utility/ruby/modules/test/test.cpp"
)

set(SOURCE_FILES
	${ROOT_SOURCE_FILES}
	${UTILITY_FILE_SOURCE_FILES}
	${UTILITY_JSON_SOURCE_FILES}
	${UTILITY_RUBY_SOURCE_FILES}
	${UTILITY_RUBY_MODULE_SOURCE_FILES}
	${RUBY_MODULE_TEST_SOURCE_FILES}
)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

source_group("Include" FILES ${ROOT_HEADER_FILES})
source_group("Include\\Utility" FILES ${UTILITY_HEADER_FILES})
source_group("Include\\Utility\\File" FILES ${UTILITY_FILE_HEADER_FILES})
source_group("Include\\Utility\\JSON" FILES ${UTILITY_JSON_HEADER_FILES})
source_group("Include\\Utility\\Ruby" FILES ${UTILITY_RUBY_HEADER_FILES})
source_group("Include\\Utility\\Ruby\\Modules" FILES ${UTILITY_RUBY_MODULE_HEADER_FILES})
source_group("Include\\Utility\\Ruby\\Modules\\Test" FILES ${RUBY_MODULE_TEST_HEADER_FILES})

source_group("Source" FILES ${ROOT_SOURCE_FILES})
source_group("Source\\Utility")
source_group("Source\\Utility\\File" FILES ${UTILITY_FILE_SOURCE_FILES})
source_group("Source\\Utility\\JSON" FILES ${UTILITY_JSON_SOURCE_FILES})
source_group("Source\\Utility\\Ruby" FILES ${UTILITY_RUBY_SOURCE_FILES})
source_group("Source\\Utility\\Ruby\\Modules" FILES ${UTILITY_RUBY_MODULE_SOURCE_FILES})
source_group("Source\\Utility\\Ruby\\Modules\\Test" FILES ${RUBY_MODULE_TEST_SOURCE_FILES})

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
	message(STATUS "OpenGL Found")
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
endif()

find_package(RUBY REQUIRED)
if(RUBY_FOUND)
	message(STATUS "Ruby ${RUBY_VERSION} Found")
	include_directories(${RUBY_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} ${RUBY_LIBRARY})
endif()