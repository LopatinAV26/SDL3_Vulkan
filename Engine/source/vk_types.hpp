#pragma once

#include <memory>
#include <optional>
#include <string>
#include <print>
#include <vector>
#include <span>
#include <array>
#include <functional>
#include <deque>
#include <print>

#include <vulkan/vulkan.h>
#include <vulkan/vk_enum_string_helper.h>

#include <vk_mem_alloc.h>

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

struct Vertex
{
	glm::vec3 position;
	float uv_x;
	glm::vec3 normal;
	float uv_y;
	glm::vec4 color;
};

struct AllocatedBuffer
{
	VkBuffer buffer;
	VmaAllocation allocation;
	VmaAllocationInfo info;
};

struct AllocatedImage
{
	VkImage image;
	VkImageView imageView;
	VmaAllocation allocation;
	VkExtent3D imageExtent;
	VkFormat imageFormat;
};

// holds the resources needed for a mesh
struct GPUMeshBuffers
{
	AllocatedBuffer indexBuffer;
	AllocatedBuffer vertexBuffer;
	VkDeviceAddress vertexBufferAddress;
};

// push constants for our mesh object draw
struct GPUDrawPushConstants
{
	glm::mat4 worldMatrix;
	VkDeviceAddress vertexBuffer;
};

#define VK_CHECK(x)                                                        \
	do                                                                     \
	{                                                                      \
		VkResult err = x;                                                  \
		if (err)                                                           \
		{                                                                  \
			std::println("Detected Vulkan error: {}", string_VkResult(err)); \
			abort();                                                       \
		}                                                                  \
	} while (0)