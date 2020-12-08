IF (WIN32)
    configure_file(day6_sample_input.txt day6_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day6_input.txt day6_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day6_sample_input.txt day6_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day6_input.txt day6_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day6 app.cpp)
target_compile_features(day6 PRIVATE cxx_std_17)

target_link_libraries(day6 PRIVATE day6-core fmt::fmt)

if(MSVC)
    target_compile_options(day6 PRIVATE /W4 /WX)
else()
    target_compile_options(day6 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
