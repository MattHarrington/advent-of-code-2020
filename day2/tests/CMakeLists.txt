find_package(doctest CONFIG REQUIRED)

configure_file(../apps/day2_input.txt day2_input.txt COPYONLY)
configure_file(../apps/day2_sample_input.txt day2_sample_input.txt COPYONLY)

# Tests need to be added as executables first
add_executable(day2-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day2-tests PRIVATE cxx_std_17)

# Should be linked to the main library, as well as GTest
target_link_libraries(day2-tests PRIVATE day2-core doctest::doctest)

