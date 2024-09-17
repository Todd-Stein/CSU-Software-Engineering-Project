# CMakeList.txt : CMake project for videoEditorProject, include source and define
# project specific logic here.
#

# Add source to this project's executable.

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(./thirdparties/SDL)

set(BUILD_SHARED_LIBS OFF)

add_executable (videoEditorProject "main.cpp")

include_directories(./thirdparties/SDL/include/)

#link_directories(./thirdparties/SDL/x64/)

target_link_libraries(videoEditorProject PRIVATE SDL3-static)

#target_include_directories(videoEditorProject PRIVATE ./thirdparties/SDL/include/SDL3/)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET videoEditorProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
