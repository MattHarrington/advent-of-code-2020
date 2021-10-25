find_package(doctest CONFIG REQUIRED)

IF (WIN32)
    configure_file(../apps/day18_sample_input.txt day18_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(../apps/day18_input.txt day18_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(../apps/day18_sample_input.txt day18_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(../apps/day18_input.txt day18_input.txt NEWLINE_STYLE UNIX)
ENDIF()

# Tests need to be added as executables first
add_executable(day18-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day18-tests PRIVATE cxx_std_17)

target_link_libraries(day18-tests PRIVATE day18-core doctest::doctest)

if(MSVC)
    target_compile_options(day18-tests PRIVATE /W4 /WX)
else()
    target_compile_options(day18-tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
