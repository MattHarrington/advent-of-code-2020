IF (WIN32)
    configure_file(day17_sample_input.txt day17_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day17_input.txt day17_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day17_sample_input.txt day17_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day17_input.txt day17_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day17 app.cpp)
target_compile_features(day17 PRIVATE cxx_std_17)

target_link_libraries(day17 PRIVATE day17-core fmt::fmt)

if(MSVC)
    target_compile_options(day17 PRIVATE /W4 /WX)
else()
    target_compile_options(day17 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
