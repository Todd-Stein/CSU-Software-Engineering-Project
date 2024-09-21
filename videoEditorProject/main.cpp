#include <iostream>

#include <SDL3/SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl3.h>
#include <backends/imgui_impl_sdlrenderer3.h>

int main(int argc, char* argv[]) {
	//SDL setup
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Couldn't initialize SDL!", SDL_GetError(), NULL);
		return EXIT_FAILURE;
	}
	SDL_Window* window = SDL_CreateWindow("Main Window", 640, 480, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	SDL_SetRenderVSync(renderer, 1);
	if (renderer == nullptr) {
		std::cout << "Failed to initialize renderer" << std::endl;
		return EXIT_FAILURE;
	}

	SDL_ShowWindow(window);

	//imgui setup
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	

	ImGui::StyleColorsClassic();

	ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer3_Init(renderer);

	SDL_Event evt;
	bool run = true;
	while (run) {
		while (SDL_PollEvent(&evt)) {
			std::cout << "window test" << std::endl;
			switch (evt.type) {
			case SDL_EVENT_QUIT:
				run = false;
				std::cout << "Quit" << std::endl;
				break;
			}
		}
		//render IMGUI
		ImGui_ImplSDLRenderer3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("IMGUI test");
		bool val;
		ImGui::Checkbox("test checkbox", &val);
		ImGui::End();

		ImGui::Render();
		SDL_SetRenderDrawColorFloat(renderer, 1.0f, 1.0f, 1.0f, 0.0f);
		SDL_RenderClear(renderer);
		ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();
	return EXIT_SUCCESS;

}