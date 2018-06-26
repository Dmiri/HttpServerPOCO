set (MY_PROJECT "HttpServer")

project(${MY_PROJECT})
cmake_minimum_required(VERSION 3.3.2)

if ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "amd64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "AMD64" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
    set (CMAKE_SIZEOF_VOID_P 8)

    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS TRUE)
    set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS FALSE)
	
elseif ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86" OR "${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "X86")
	set (CMAKE_SIZEOF_VOID_P 4)
	
	set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS FALSE)
	set_property (GLOBAL PROPERTY FIND_LIBRARY_USE_LIB32_PATHS TRUE)
	
	if(UNIX)
	option(USE_CLANG "build application with clang" OFF) # OFF is the default
	if(USE_CLANG)
		if(Debug)
			SET (CMAKE_CXX_FLAGS_INIT                "-Wall")
			SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
			SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
			SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O4 -DNDEBUG")
			SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
		else()
			set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
		endif(Debug)

	else
	
	endif(USE_CLANG)
	
		# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
		# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
		# set (CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32")
		# SET(CMAKE_SHARED_LINK_FLAGS "${CMAKE_SHARED_LINK_FLAGS} -m32")
		# SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -m32")
	elseif(WIN32)
		if(Debug)
			set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
			set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -Wall")
		else()
			set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
		endif(Debug)
	endif (UNIX)
else()
		message (FATAL_ERROR "Unsupported CPU: ${CMAKE_SYSTEM_PROCESSOR}")
endif ()

if(Debug)
	SET(CMAKE_SHARED_LINK_FLAGS ${CONAN_LIBS_DEBUG} ${CONAN_LIBS})
	ADD_DEFINITIONS( -DMY_DEBUG_MODE=1)
else()
	SET(CMAKE_SHARED_LINK_FLAGS ${CONAN_LIBS_RELEASE} ${CONAN_LIBS})
endif(Debug)

add_definitions("-std=c++14")


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
