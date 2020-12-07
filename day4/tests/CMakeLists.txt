find_package(doctest CONFIG REQUIRED)

IF (WIN32)
    configure_file(../apps/day4_sample_input.txt day4_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(../apps/day4_input.txt day4_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(../apps/day4_sample_input.txt day4_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(../apps/day4_input.txt day4_input.txt NEWLINE_STYLE UNIX)
ENDIF()

# Tests need to be added as executables first
add_executable(day4-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day4-tests PRIVATE cxx_std_17)

target_link_libraries(day4-tests PRIVATE day4-core doctest::doctest)

if(MSVC)
    target_compile_options(day4-tests PRIVATE /W4 /WX)
else()
    target_compile_options(day4-tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
