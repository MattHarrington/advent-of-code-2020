add_executable(day15 app.cpp)
target_compile_features(day15 PRIVATE cxx_std_17)

target_link_libraries(day15 PRIVATE day15-core fmt::fmt)

if(MSVC)
    target_compile_options(day15 PRIVATE /W4 /WX)
else()
    target_compile_options(day15 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
