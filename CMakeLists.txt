

cmake_minimum_required (VERSION 3.6)
project (ao)

set (BOOST_INCLUDEDIR "C:/Boost/include/boost-1_61" )
set (BOOST_LIBRARYDIR "C:/Boost/lib" )
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME ON)

find_package(Boost 1.61 COMPONENTS coroutine REQUIRED)
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


set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

add_executable(ao main.cpp test.cpp ao/all.h)

set (CMAKE_EXE_LINKER_FLAGS "-SAFESEH:NO")

target_link_libraries( ao ${Boost_LIBRARIES} )
target_link_libraries( ao ${GTEST_LIBRARIES} )
target_link_libraries( ao ${GMOCK_LIBRARIES} )

target_link_libraries( ao GTest::GTest GTest::Main)


