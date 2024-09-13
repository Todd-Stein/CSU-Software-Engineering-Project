# CMakeList.txt : CMake project for videoEditorProject, include source and define
# project specific logic here.
#

# Add source to this project's executable.

add_executable (videoEditorProject "main.cpp")

target_include_directories(videoEditorProject PRIVATE ./thirdparties/SDL/include/SDL3/)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET videoEditorProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
