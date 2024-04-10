cmake_minimum_required(VERSION 3.15)
project(meltrix VERSION 0.0.6 DESCRIPTION "A simple and templated C++ Matrix library" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List of source files
set(MELTRIX_SOURCES
    src/Base.cpp
)

# List of header files
set(MELTRIX_HEADERS
    include/meltrix/Base.h
)

# Create the meltrix library target
add_library(meltrix ${MELTRIX_SOURCES})

# Set the include directories for the library target
target_include_directories(meltrix PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set the public headers for the library target
set_target_properties(meltrix PROPERTIES PUBLIC_HEADER "${MELTRIX_HEADERS}")

# Installation rules
install(TARGETS meltrix DESTINATION lib)
install(FILES ${MELTRIX_HEADERS} DESTINATION include/meltrix)