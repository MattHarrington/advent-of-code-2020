IF (WIN32)
    configure_file(day9_sample_input.txt day9_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day9_input.txt day9_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day9_sample_input.txt day9_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day9_input.txt day9_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day9 app.cpp)
target_compile_features(day9 PRIVATE cxx_std_17)

target_link_libraries(day9 PRIVATE day9-core fmt::fmt)

if(MSVC)
    target_compile_options(day9 PRIVATE /W4 /WX)
else()
    target_compile_options(day9 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
