

cmake_minimum_required (VERSION 3.6)
project (ao)

set (BOOST_ROOT "C:/boost_1_64_0")
set (Boost_USE_STATIC_RUNTIME OFF)
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_DEBUG_RUNTIME ON)

find_package(Boost 1.64.0 COMPONENTS context fiber REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set (GTEST_INCLUDE_DIR "d:/programming/googletest-release-1.8.0/googletest/include")
set (GTEST_LIBRARY "d:/programming/googletest-release-1.8.0/build/googlemock/gtest/Debug/gtest.lib")
set (GTEST_MAIN_LIBRARY "d:/programming/googletest-release-1.8.0/build/googlemock/gtest/Debug/gtest_main.lib")

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (GMOCK_INCLUDE_DIR "d:/programming/googletest-release-1.8.0/googlemock/include")
set (GMOCK_LIBRARY "d:/programming/googletest-release-1.8.0/build/googlemock/Debug/gmock.lib")
set (GMOCK_MAIN_LIBRARY "d:/programming/googletest-release-1.8.0/build/googlemock/Debug/gmock_main.lib")

enable_testing()
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS_RELEASE "/MD /Zi /Od /std:c++14")
set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Od /std:c++14")


add_executable(ao main.cpp fiber_test.cpp)


set (CMAKE_EXE_LINKER_FLAGS "-SAFESEH:NO")

target_link_libraries( ao ${Boost_LIBRARIES} Boost::disable_autolinking  Boost::diagnostic_definitions)
target_link_libraries( ao ${GTEST_LIBRARIES} )
target_link_libraries( ao ${GMOCK_LIBRARIES} )

target_link_libraries( ao GTest::GTest GTest::Main)


