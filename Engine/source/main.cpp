#include <SDL3/SDL_main.h>
#include "vk_engine.hpp"

int main(int argc, char* argv[])
{
	atexit(SDL_Quit);

	VulkanEngine engine;

	engine.init();

	engine.run();

	engine.cleanup();

	return 0;
}