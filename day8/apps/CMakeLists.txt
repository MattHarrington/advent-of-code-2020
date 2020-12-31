IF (WIN32)
    configure_file(day8_sample_input.txt day8_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day8_input.txt day8_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day8_sample_input.txt day8_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day8_input.txt day8_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day8 app.cpp)
target_compile_features(day8 PRIVATE cxx_std_17)

target_link_libraries(day8 PRIVATE day8-core fmt::fmt)

if(MSVC)
    target_compile_options(day8 PRIVATE /W4 /WX)
else()
    target_compile_options(day8 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
