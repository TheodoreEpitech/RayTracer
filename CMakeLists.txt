cmake_minimum_required(VERSION 3.20.0)
project(raytracer
    VERSION 1.0
    DESCRIPTION "Raytracer"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Core
file(GLOB_RECURSE SRC "./src/*.cpp")

# add SFML
if (APPLE)
    set(SFML_INCLUDE_DIRS /opt/homebrew/include)
    set(SFML_LIBRARIES
        /opt/homebrew/lib/libsfml-system.dylib
        /opt/homebrew/lib/libsfml-window.dylib
        /opt/homebrew/lib/libsfml-graphics.dylib)
else()
    set(SFML_LIBRARIES sfml-graphics sfml-audio sfml-window sfml-system)
endif()

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBRARIES})

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# add gprof
target_link_libraries(${PROJECT_NAME} PRIVATE "-pg")

# Make executable in root directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "raytracer"
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_include_directories(${PROJECT_NAME} PRIVATE "./src" ${SFML_INCLUDE_DIRS})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wformat=2
    -Wswitch-default -Wcast-align -Wpointer-arith -Wundef -Wcast-qual
    -Wshadow -Wwrite-strings -Wconversion -Wunreachable-code -Wstrict-aliasing=2
    -fno-common -fstrict-aliasing -Wunused-macros -fno-gnu-unique
)

if (CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
    target_compile_options(${PROJECT_NAME} PRIVATE -O2)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3")
endif()

if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(${PROJECT_NAME} PRIVATE -O2)
    set(CMAKE_CXX_FLAGS_RELEASE "-g3")
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -O0)
    set(CMAKE_CXX_FLAGS_DEBUG "-g3")
    set(CMAKE_CXX_FLAGS_DEBUG "-fomit-frame-pointer -fsanitize=address")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()
