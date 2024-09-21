# CMakeList.txt : CMake project for videoEditorProject, include source and define
# project specific logic here.
#

# Add source to this project's executable.

set(SDL_STATIC ON)
set(SDL_SHARED OFF)
set(SDL_EXAMPLES ON)

add_subdirectory(./thirdparties/SDL)

#file(GLOB IMGUI_CPP_FILES ./thirdparties/imgui/*.cpp)
add_library("ImGui" STATIC ./thirdparties/imgui/imgui.cpp ./thirdparties/imgui/imgui_draw.cpp ./thirdparties/imgui/imgui_demo.cpp ./thirdparties/imgui/imgui_tables.cpp ./thirdparties/imgui/imgui_widgets.cpp ./thirdparties/imgui/backends/imgui_impl_sdl3.cpp ./thirdparties/imgui/backends/imgui_impl_sdlrenderer3.cpp)
target_include_directories("ImGui" PUBLIC ./thirdparties/imgui/)

add_executable (videoEditorProject "main.cpp")

target_link_libraries(videoEditorProject PRIVATE SDL3-static)
target_link_libraries(videoEditorProject PRIVATE ImGui)

include_directories(./thirdparties/SDL/include/)

include_directories(./thirdparties/imgui/)

#link_directories(./thirdparties/SDL/x64/)



#target_include_directories(videoEditorProject PRIVATE ./thirdparties/SDL/include/SDL3/)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET videoEditorProject PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
