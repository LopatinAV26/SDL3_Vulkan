#include "vk_loader.hpp"

#include <iostream>
#include "stb_image.h"
#include "vk_engine.hpp"
#include "vk_initializers.hpp"
#include "vk_types.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include "fastgltf/core.hpp"
#include "fastgltf/types.hpp"
#include "fastgltf/tools.hpp"

std::optional<std::vector<std::shared_ptr<MeshAsset>>> loadGltfMeshes(VulkanEngine* engine, std::filesystem::path filePath)
{
	std::cout << "Loading GLTF: " << filePath << std::endl;

	fastgltf::GltfDataBuffer data;
	data.FromPath(filePath);

	constexpr auto gltfOptions = fastgltf::Options::LoadExternalBuffers;

	fastgltf::Asset gltf;
	fastgltf::Parser parser{};

	auto load = parser.loadGltfBinary(data, filePath.parent_path(), gltfOptions);
	if (load) {
		gltf = std::move(load.get());
	}
	else {
		std::print("Failed to load glTF: {} \n", fastgltf::to_underlying(load.error()));
		return{};
	}
}
