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

add_executable(unit_tests
    main.cpp
)

target_link_libraries(unit_tests PRIVATE meltrix Catch2::Catch2WithMain)

add_test(
    NAME meltrix_unit_tests
    COMMAND unit_tests
)