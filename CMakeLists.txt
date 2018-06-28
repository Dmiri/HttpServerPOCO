set (MY_PROJECT "HttpServer")

project(${MY_PROJECT})
cmake_minimum_required(VERSION 3.3.2)

add_definitions("-std=c++14")

if ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
    set (CMAKE_SIZEOF_VOID_P 8)

    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)
    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS FALSE)
	
elseif ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "X86")
	set (CMAKE_SIZEOF_VOID_P 4)
	
	set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
	set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS TRUE)
else()
		message (FATAL_ERROR "Unsupported CPU: ${CMAKE_SYSTEM_PROCESSOR}")
endif ()

if(Debug)
	SET(CMAKE_SHARED_LINK_FLAGS ${CONAN_LIBS_DEBUG} ${CONAN_LIBS})
	ADD_DEFINITIONS( -DMY_DEBUG_MODE=1)
else()
	SET(CMAKE_SHARED_LINK_FLAGS ${CONAN_LIBS_RELEASE} ${CONAN_LIBS})
endif(Debug)

if (UNIX)
	# SET(CMAKE_CXX_FLAGS "-Wall -fno-rtti")
	# SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
	# SET(CMAKE_CXX_FLAGS_RELEASE "-O2")
	# SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")
	if("{CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "{CMAKE_CXX_COMPILER_ID}" STREQUAL "clang")
		set(CMAKE_C_COMPILER /usr/bin/clang)
		set(CMAKE_CXX_COMPILER /usr/bin/clang++)
	elseif( "{CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "{CMAKE_CXX_COMPILER_ID}" STREQUAL "gnu")
		set(CMAKE_C_COMPILER /usr/bin/gcc)
		set(CMAKE_CXX_COMPILER /usr/bin/g++)
	endif()
elseif(WIN32)

else()
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Wall")
	set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
endif (UNIX)

include(${CMAKE_CURRENT_LIST_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

# the variable "project_SRC" contains all .h and .cpp files of this project
set(project_SRC
	src/HttpServer.cpp
	src/Listener.h
	src/Handlers.h
	src/Handlers.cpp
	src/CommonRequestHandler.h
	src/CommonRequestHandler.cpp
	src/Config.h
)
add_executable(${MY_PROJECT} ${project_SRC})
target_link_libraries(${MY_PROJECT} ${CONAN_LIBS})
