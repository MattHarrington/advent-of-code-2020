configure_file(sample_input.txt sample_input.txt COPYONLY)
configure_file(day1_input.txt day1_input.txt COPYONLY)

add_executable(day1 app.cpp)
target_compile_features(day1 PRIVATE cxx_std_17)

target_link_libraries(day1 PRIVATE day1-core fmt::fmt)
