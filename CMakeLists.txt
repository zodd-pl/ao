

cmake_minimum_required (VERSION 3.6)
project (ao)

set (BOOST_INCLUDEDIR "C:/Boost/include/boost-1_61" )
set (BOOST_LIBRARYDIR "C:/Boost/lib" )
set (Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.61 COMPONENTS coroutine REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(ao test.cpp)

set (CMAKE_EXE_LINKER_FLAGS "-SAFESEH:NO")
target_link_libraries( ao ${Boost_LIBRARIES} )

