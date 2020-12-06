IF (WIN32)
    configure_file(day1_sample_input.txt day1_sample_input.txt NEWLINE_STYLE WIN32)
    configure_file(day1_input.txt day1_input.txt NEWLINE_STYLE WIN32)
ELSE()
    configure_file(day1_sample_input.txt day1_sample_input.txt NEWLINE_STYLE UNIX)
    configure_file(day1_input.txt day1_input.txt NEWLINE_STYLE UNIX)
ENDIF()

add_executable(day1 app.cpp)
target_compile_features(day1 PRIVATE cxx_std_17)

target_link_libraries(day1 PRIVATE day1-core fmt::fmt)
