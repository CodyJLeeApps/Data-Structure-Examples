#=====================================================
# This file contains global compiler flags for different platforms
#=====================================================
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    set(CMAKE_CXX_FLAGS_RELEASE "-g --std=c++14 --std=c++1y")
    set(CMAKE_CXX_FLAGS_DEBUG "-g --std=c++14 --std=c++1y")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -g -Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MINGW")
    set(CMAKE_CXX_FLAGS_RELEASE "-Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Wl,--no-as-needed -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0")
endif()
