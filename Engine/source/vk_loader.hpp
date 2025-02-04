#pragma once

#include <unordered_map>
#include <filesystem>

#include "vk_types.hpp"

class VulkanEngine;

struct GeoSurface
{
    uint32_t startIndex;
    uint32_t count;
};

struct MeshAsset
{
    std::string name;

    std::vector<GeoSurface> surfaces;
    GPUMeshBuffers meshBuffers;
};

std::optional<std::vector<std::shared_ptr<MeshAsset>>> loadGltfMeshes(VulkanEngine *engine, std::filesystem::path filePath);