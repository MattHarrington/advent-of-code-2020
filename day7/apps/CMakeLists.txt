IF (WIN32)
    configure_file(day7_sample_input.txt day7_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day7_input.txt day7_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day7_sample_input.txt day7_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day7_input.txt day7_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day7 app.cpp)
target_compile_features(day7 PRIVATE cxx_std_17)

target_link_libraries(day7 PRIVATE day7-core fmt::fmt)

if(MSVC)
    target_compile_options(day7 PRIVATE /W4 /WX)
else()
    target_compile_options(day7 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
