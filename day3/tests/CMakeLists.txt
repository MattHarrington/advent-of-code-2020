find_package(doctest CONFIG REQUIRED)

IF (WIN32)
    configure_file(../apps/day3_sample_input.txt day3_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(../apps/day3_input.txt day3_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(../apps/day3_sample_input.txt day3_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(../apps/day3_input.txt day3_input.txt NEWLINE_STYLE UNIX)
ENDIF()

# Tests need to be added as executables first
add_executable(day3-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day3-tests PRIVATE cxx_std_17)

target_link_libraries(day3-tests PRIVATE day3-core doctest::doctest)
