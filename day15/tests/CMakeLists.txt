find_package(doctest CONFIG REQUIRED)

# Tests need to be added as executables first
add_executable(day15-tests testlib.cpp)

# I'm using C++17 in the test
target_compile_features(day15-tests PRIVATE cxx_std_17)

target_link_libraries(day15-tests PRIVATE day15-core doctest::doctest)

if(MSVC)
    target_compile_options(day15-tests PRIVATE /W4 /WX)
else()
    target_compile_options(day15-tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
