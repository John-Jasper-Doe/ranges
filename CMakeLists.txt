# ----------------------------------------------------------------------------
#  Root CMake file for Range Project
#
#    From the off-tree build directory, invoke:
#      $ cmake <PATH_TO_RANGE_ROOT>
#
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(range VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(range VERSION 0.0.1)
endif ()

# find packages ...
find_package(Threads)
#find_package(Boost COMPONENTS filesystem program_options regex REQUIRED)

# Conan ...
include(conanbuildinfo.cmake)
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Output binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# For Qt
#set(Qt5Core_DIR "/opt/q5130/5.13.0/gcc_64/lib/cmake/Qt5Core")
#set(Qt5_DIR "/opt/q5130/5.13.0/gcc_64/lib/cmake/Qt5")
#set(QT_QMAKE_EXECUTABLE "/opt/q5130/5.13.0/gcc_64/bin/qmake.exe")

# File path
file(GLOB DIR_ROOT_SRCS src/*.cpp)
file(GLOB DIR_ROOT_HDRS src/*.hpp)

include_directories(${CONAN_INCLUDE_DIRS})

# make executable file for application
add_executable(${PROJECT_NAME} ${DIR_ROOT_SRCS} ${DIR_ROOT_HDRS})

set_target_properties(${PROJECT_NAME} PROPERTIES
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                LINK_LIBRARIES pthread
                COMPILE_OPTIONS "-g;-O0;-Wall;-Wextra;-Werror;-Wpedantic"
                )

#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

# install to bin folder our binaries
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

## generate .deb package
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT john.jasper.doe@gmail.com)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

## include will generate proper code for .deb generation
include(CPack)
