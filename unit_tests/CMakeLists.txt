# Get Catch2
find_package(Catch2 3 QUIET)

if (NOT ${Catch2_FOUND})
    message("Catch2 not found, fetching from git")
    Include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
    )
    FetchContent_MakeAvailable(Catch2)
endif()

# Set test sources
set(TEST_SOURCES
    VectorTests.cpp
)

# Create tests for each file
foreach(test ${TEST_SOURCES})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test})
    target_link_libraries(${testName} PRIVATE meltrix Catch2::Catch2WithMain)
    add_test(NAME ${testName} COMMAND ${testName})
endforeach(test)