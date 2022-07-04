cmake_minimum_required(VERSION 3.14)

project(QMessenger LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/install/lib)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)


file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_CURRENT_LIST_DIR}/source/*.h)

file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/source/*.*)

file(COPY ${HEADER_FILES} DESTINATION ${CMAKE_CURRENT_LIST_DIR}/install/include FOLLOW_SYMLINK_CHAIN)

add_executable(QMessenger ${PROJECT_SOURCES})
target_link_libraries(QMessenger Qt${QT_VERSION_MAJOR}::Core)

if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    add_library(LibQMessengerD
        STATIC
    ${PROJECT_SOURCES})

    target_link_libraries(LibQMessengerD Qt${QT_VERSION_MAJOR}::Core)
elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    add_library(LibQMessenger
        STATIC
    ${PROJECT_SOURCES})

    target_link_libraries(LibQMessenger Qt${QT_VERSION_MAJOR}::Core)
else()
endif()
