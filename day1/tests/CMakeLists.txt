find_package(GTest CONFIG REQUIRED)

IF (WIN32)
    configure_file(../apps/day1_sample_input.txt day1_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(../apps/day1_input.txt day1_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(../apps/day1_sample_input.txt day1_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(../apps/day1_input.txt day1_input.txt NEWLINE_STYLE UNIX)
ENDIF()

# Tests need to be added as executables first
add_executable(day1-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day1-tests PRIVATE cxx_std_17)

# Should be linked to the main library, as well as GTest
target_link_libraries(day1-tests PRIVATE day1-core GTest::gtest GTest::gtest_main)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME day1-tests COMMAND day1-tests) # Command can be a target

