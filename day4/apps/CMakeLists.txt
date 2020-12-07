IF (WIN32)
    configure_file(day4_sample_input.txt day4_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day4_input.txt day4_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day4_sample_input.txt day4_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day4_input.txt day4_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day4 app.cpp)
target_compile_features(day4 PRIVATE cxx_std_17)

target_link_libraries(day4 PRIVATE day4-core fmt::fmt)

if(MSVC)
    target_compile_options(day4 PRIVATE /W4 /WX)
else()
    target_compile_options(day4 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
