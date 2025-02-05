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
	//open mesh------------
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
	//open mesh--------------------

	//load mesh---------------------
	std::vector<std::shared_ptr<MeshAsset>> meshes;

	//use the same vectors for all meshes so that the memory doesnt reallocate as often
	std::vector<uint32_t> indices;
	std::vector<Vertex> vertices;
	for(fastgltf::Mesh& mesh: gltf.meshes){
		MeshAsset newMesh;
		newMesh.name = mesh.name;

		//clear the mesh arrays each mesh, we dont want to merge them by error
		indices.clear();
		vertices.clear();

		for(auto&& p: mesh.primitives){
			GeoSurface newSurface;
			newSurface.startIndex = static_cast<uint32_t>(indices.size());
			newSurface.count = static_cast<uint32_t>(gltf.accessors[p.indicesAccessor.value()].count);

			size_t initial_vtx = vertices.size();

			//load indexes
			{
				fastgltf::Accessor& indexaccessor = gltf.accessors[p.indicesAccessor.value()];
				indices.reserve(indices.size() + indexaccessor.count);

				fastgltf::iterateAccessor<std::uint32_t>(gltf, indexaccessor, [&](std::uint32_t idx){
					indices.push_back(idx + initial_vtx);
				});
			}

			//load vertex positions
			{
				fastgltf::Accessor& posAccessor = gltf.accessors[p.findAttribute("POSITION")->accessorIndex];
				vertices.resize(vertices.size() + posAccessor.count);

				fastgltf::iterateAccessorWithIndex<glm::vec3>(gltf, posAccessor, [&](glm::vec3 v, size_t index){
					Vertex newVtx;
				});
			}
		}
	}
}
