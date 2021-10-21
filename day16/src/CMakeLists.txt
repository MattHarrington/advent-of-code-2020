# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${day16_SOURCE_DIR}/include/*.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(day16-core lib.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(day16-core PUBLIC ../include)

target_link_libraries(day16-core PRIVATE Eigen3::Eigen)

# All users of this library will need at least C++17
target_compile_features(day16-core PUBLIC cxx_std_17)

# Increase warnings
if(MSVC)
    target_compile_options(day16-core PRIVATE /W4 /WX)
else()
    target_compile_options(day16-core PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
