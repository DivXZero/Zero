cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME "Zero")
project(${PROJECT_NAME})

include_directories("Include")
include_directories("Dependencies/rapidjson/include")

set(ROOT_HEADER_FILES
	"Include/Zero.h"
)

set(UTILITY_HEADER_FILES
	"Include/Utility/Common.h"
)

set(UTILITY_FILE_HEADER_FILES
	"Include/Utility/File/File.h"
	"Include/Utility/File/SharedFile.h"
)

set(UTILITY_JSON_HEADER_FILES
	"Include/Utility/JSON/JSON.h"
	"Include/Utility/JSON/SharedJSON.h"
)

set(HEADER_FILES
	${ROOT_HEADER_FILES}
	${UTILITY_HEADER_FILES}
	${UTILITY_FILE_HEADER_FILES}
	${UTILITY_JSON_HEADER_FILES}
)

set(ROOT_SOURCE_FILES
	"Source/Zero.cpp"
)

set(UTILITY_FILE_SOURCE_FILES
	"Source/Utility/File/File.cpp"
)

set(UTILITY_JSON_SOURCE_FILES
	"Source/Utility/JSON/JSON.cpp"
)

set(SOURCE_FILES
	${ROOT_SOURCE_FILES}
	${UTILITY_FILE_SOURCE_FILES}
	${UTILITY_JSON_SOURCE_FILES}
)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

source_group("Include" FILES ${ROOT_HEADER_FILES})
source_group("Include\\Utility" FILES ${UTILITY_HEADER_FILES})
source_group("Include\\Utility\\File" FILES ${UTILITY_FILE_HEADER_FILES})
source_group("Include\\Utility\\JSON" FILES ${UTILITY_JSON_HEADER_FILES})

source_group("Source" FILES ${ROOT_SOURCE_FILES})
source_group("Source\\Utility")
source_group("Source\\Utility\\File" FILES ${UTILITY_FILE_SOURCE_FILES})
source_group("Source\\Utility\\JSON" FILES ${UTILITY_JSON_SOURCE_FILES})