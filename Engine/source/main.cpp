#include <SDL3/SDL_main.h>
#include "vk_engine.hpp"
#include <memory>

int main(int argc, char* argv[])
{
	atexit(SDL_Quit);

	auto engine = std::make_unique<VulkanEngine>();

	//VulkanEngine engine;

	engine->init();

	engine->run();

	engine->cleanup();

	return 0;
}