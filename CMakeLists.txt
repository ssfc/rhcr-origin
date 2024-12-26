cmake_minimum_required (VERSION 3.22)
project(lifelong)
set(CMAKE_CXX_STANDARD 11)

IF(NOT CMAKE_BUILD_TYPE)
    #SET(CMAKE_BUILD_TYPE "DEBUG")
    SET(CMAKE_BUILD_TYPE "RELEASE")
    #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
    #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()

if (WIN32)
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows")
endif()

include_directories("inc")
file(GLOB SOURCES "src/*.cpp")

# Find Boost
find_package( Boost 1.49.0 REQUIRED COMPONENTS program_options system filesystem)
include_directories( ${Boost_INCLUDE_DIRS} )


add_executable(lifelong ${SOURCES} )
target_link_libraries(lifelong ${Boost_LIBRARIES})
