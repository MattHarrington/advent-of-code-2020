IF (WIN32)
    configure_file(day18_sample_input.txt day18_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day18_input.txt day18_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day18_sample_input.txt day18_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day18_input.txt day18_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day18 app.cpp)
target_compile_features(day18 PRIVATE cxx_std_17)

target_link_libraries(day18 PRIVATE day18-core fmt::fmt)

if(MSVC)
    target_compile_options(day18 PRIVATE /W4 /WX)
else()
    target_compile_options(day18 PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
