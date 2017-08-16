project(rttr_autoreg)
cmake_Minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  message(WARNING "found conanbuildinfo, using conan libraries for build")
  conan_basic_setup()
endif()


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/)
message(STATUS ${CMAKE_MODULE_PATH})


find_package(rttr REQUIRED)
find_package(LibClang REQUIRED)

message(${LIBCLANG_LIBDIR})
message(${LIBCLANG_INCLUDE_DIRS})

#find jinja2 template engine
find_library(jinja2 Jinja2CppLight)
message("Jinja2 library : ${jinja2}")



add_executable(libclang_play libclang_play.cpp)
target_link_libraries(libclang_play ${LIBCLANG_LIBRARIES} ${jinja2})
target_include_directories(libclang_play PRIVATE ${LIBCLANG_LIBDIR})
