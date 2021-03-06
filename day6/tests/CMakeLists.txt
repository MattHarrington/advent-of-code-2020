find_package(doctest CONFIG REQUIRED)

IF (WIN32)
    configure_file(../apps/day6_sample_input.txt day6_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(../apps/day6_input.txt day6_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(../apps/day6_sample_input.txt day6_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(../apps/day6_input.txt day6_input.txt NEWLINE_STYLE UNIX)
ENDIF()

# Tests need to be added as executables first
add_executable(day6-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day6-tests PRIVATE cxx_std_17)

target_link_libraries(day6-tests PRIVATE day6-core doctest::doctest)

if(MSVC)
    target_compile_options(day6-tests PRIVATE /W4 /WX)
else()
    target_compile_options(day6-tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
