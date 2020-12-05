configure_file(day2_sample_input.txt day2_sample_input.txt COPYONLY)
configure_file(day2_input.txt day2_input.txt COPYONLY)

add_executable(day2 app.cpp)
target_compile_features(day2 PRIVATE cxx_std_17)

target_link_libraries(day2 PRIVATE day2-core fmt::fmt)
