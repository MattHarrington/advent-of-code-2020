IF (WIN32)
    configure_file(day3_sample_input.txt day3_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day3_input.txt day3_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day3_sample_input.txt day3_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day3_input.txt day3_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day3 app.cpp)
target_compile_features(day3 PRIVATE cxx_std_17)

target_link_libraries(day3 PRIVATE day3-core fmt::fmt)
