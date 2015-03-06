cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME "Zero")
project(${PROJECT_NAME})

include_directories("Include")
include_directories("Dependencies/glm")
include_directories("Dependencies/rapidjson/include")
include_directories("Dependencies/ruby/usr/include/ruby-2.3.0")
include_directories("C:/ruby/include/ruby-2.3.0")
set(SFML_INCLUDE_DIR "dependencies/SFML/include")

set(ROOT_HEADER_FILES
	"include/zero.h"
	"include/game.h"
)

set(SYSTEM_HEADER_FILES
)

set(SYSTEM_GRAPHICS_HEADER_FILES
	"include/system/graphics/scene.h"
	"include/system/graphics/glscene.h"
	"include/system/graphics/scenemanager.h"
)

set(SYSTEM_WINDOW_HEADER_FILES
	"include/system/window/sharedwindow.h"
	"include/system/window/win32window.h"
	"include/system/window/sfmlwindow.h"
)

set(UTILITY_HEADER_FILES
	"include/utility/common.h"
	"include/utility/singleton.h"
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
	"include/utility/ruby/modules/zero.h"
)

set(UTILITY_RUBY_MODULE_BASE_HEADER_FILES
	"include/utility/ruby/modules/base/module.h"
	"include/utility/ruby/modules/base/class.h"
	"include/utility/ruby/modules/base/function.h"
)

set(RUBY_MODULE_TEST_HEADER_FILES
	"include/utility/ruby/modules/test/test.h"
)

set(HEADER_FILES
	${ROOT_HEADER_FILES}
	${SYSTEM_HEADER_FILES}
	${SYSTEM_GRAPHICS_HEADER_FILES}
	${SYSTEM_WINDOW_HEADER_FILES}
	${UTILITY_HEADER_FILES}
	${UTILITY_FILE_HEADER_FILES}
	${UTILITY_JSON_HEADER_FILES}
	${UTILITY_RUBY_HEADER_FILES}
	${UTILITY_RUBY_MODULE_HEADER_FILES}
	${UTILITY_RUBY_MODULE_BASE_HEADER_FILES}
	${RUBY_MODULE_TEST_HEADER_FILES}
)

set(ROOT_SOURCE_FILES
	"source/zero.cpp"
	"source/game.cpp"
)

set(SYSTEM_SOURCE_FILES
)

set(SYSTEM_GRAPHICS_SOURCE_FILES
	"source/system/graphics/scene.cpp"
	"source/system/graphics/glscene.cpp"
	"source/system/graphics/scenemanager.cpp"
)

set(SYSTEM_WINDOW_SOURCE_FILES
	"source/system/window/win32window.cpp"
	"source/system/window/sfmlwindow.cpp"
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
	"source/utility/ruby/modules/zero.cpp"
)

set(UTILITY_RUBY_MODULE_BASE_SOURCE_FILES
	"source/utility/ruby/modules/base/module.cpp"
	"source/utility/ruby/modules/base/class.cpp"
	"source/utility/ruby/modules/base/function.cpp"
)

set(RUBY_MODULE_TEST_SOURCE_FILES
	"source/utility/ruby/modules/test/test.cpp"
)

set(SOURCE_FILES
	${ROOT_SOURCE_FILES}
	${SYSTEM_SOURCE_FILES}
	${SYSTEM_GRAPHICS_SOURCE_FILES}
	${SYSTEM_WINDOW_SOURCE_FILES}
	${UTILITY_FILE_SOURCE_FILES}
	${UTILITY_JSON_SOURCE_FILES}
	${UTILITY_RUBY_SOURCE_FILES}
	${UTILITY_RUBY_MODULE_SOURCE_FILES}
	${UTILITY_RUBY_MODULE_BASE_SOURCE_FILES}
	${RUBY_MODULE_TEST_SOURCE_FILES}
)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

source_group("include" FILES ${ROOT_HEADER_FILES})
source_group("include\\system" FILES ${SYSTEM_HEADER_FILES})
source_group("include\\system\\graphics" FILES ${SYSTEM_GRAPHICS_HEADER_FILES})
source_group("include\\system\\window" FILES ${SYSTEM_WINDOW_HEADER_FILES})
source_group("include\\utility" FILES ${UTILITY_HEADER_FILES})
source_group("include\\utility\\file" FILES ${UTILITY_FILE_HEADER_FILES})
source_group("include\\utility\\json" FILES ${UTILITY_JSON_HEADER_FILES})
source_group("include\\utility\\ruby" FILES ${UTILITY_RUBY_HEADER_FILES})
source_group("include\\utility\\ruby\\modules" FILES ${UTILITY_RUBY_MODULE_HEADER_FILES})
source_group("include\\utility\\ruby\\modules\\base" FILES ${UTILITY_RUBY_MODULE_BASE_HEADER_FILES})
source_group("include\\utility\\ruby\\modules\\test" FILES ${RUBY_MODULE_TEST_HEADER_FILES})

source_group("source" FILES ${ROOT_SOURCE_FILES})
source_group("source\\system" FILES ${SYSTEM_SOURCE_FILES})
source_group("source\\system\\graphics" FILES ${SYSTEM_GRAPHICS_SOURCE_FILES})
source_group("source\\system\\window" FILES ${SYSTEM_WINDOW_SOURCE_FILES})
source_group("source\\utility")
source_group("source\\utility\\file" FILES ${UTILITY_FILE_SOURCE_FILES})
source_group("source\\utility\\json" FILES ${UTILITY_JSON_SOURCE_FILES})
source_group("source\\utility\\ruby" FILES ${UTILITY_RUBY_SOURCE_FILES})
source_group("source\\utility\\ruby\\modules" FILES ${UTILITY_RUBY_MODULE_SOURCE_FILES})
source_group("source\\utility\\ruby\\modules\\base" FILES ${UTILITY_RUBY_MODULE_BASE_SOURCE_FILES})
source_group("source\\utility\\ruby\\modules\\test" FILES ${RUBY_MODULE_TEST_SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

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

if(WIN32)
	set(SFML_STATIC_LIBRARIES TRUE)
endif()
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${SFML_DEPENDENCIES})
	target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()