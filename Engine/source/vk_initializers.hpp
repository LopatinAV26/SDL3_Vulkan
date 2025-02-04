#pragma once

#include "vk_types.hpp"

namespace vkinit
{
	VkCommandPoolCreateInfo command_pool_create_info(uint32_t qeueFamilyIndex,
													 VkCommandPoolCreateFlags flags = 0);
	VkCommandBufferAllocateInfo command_buffer_allocate_info(VkCommandPool pool,
															 uint32_t count = 1);

	VkFenceCreateInfo fence_create_info(VkFenceCreateFlags flags = 0);
	VkSemaphoreCreateInfo semaphore_create_info(VkSemaphoreCreateFlags flags = 0);

	VkCommandBufferBeginInfo command_buffer_begin_info(VkCommandBufferUsageFlags flags = 0);

	VkImageSubresourceRange image_subresource_range(VkImageAspectFlags aspectMask);

	VkSemaphoreSubmitInfo semaphore_submit_info(VkPipelineStageFlags2 stageMask, VkSemaphore semaphore);

	VkCommandBufferSubmitInfo command_buffer_submit_info(VkCommandBuffer cmd);

	VkSubmitInfo2 submit_info(VkCommandBufferSubmitInfo *cmd, VkSemaphoreSubmitInfo *signalSemaphoreInfo,
							  VkSemaphoreSubmitInfo *waitSemaphoreInfo);

	VkPresentInfoKHR present_info();

	VkImageCreateInfo image_create_info(VkFormat format, VkImageUsageFlags usageFlags, VkExtent3D extent);

	VkImageViewCreateInfo imageview_create_info(VkFormat format, VkImage image, VkImageAspectFlags aspectFlags);

	VkRenderingAttachmentInfo attachment_info(VkImageView view, VkClearValue *value,
											  VkImageLayout layout /*= VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL*/);

	VkRenderingInfo rendering_info(VkExtent2D renderExtent, VkRenderingAttachmentInfo *colorAttachment,
								   VkRenderingAttachmentInfo *depthAttachment);

	VkWriteDescriptorSet write_descriptor_image(VkDescriptorType type, VkDescriptorSet dstSet,
												VkDescriptorImageInfo *imageInfo, uint32_t binding);

	VkPipelineShaderStageCreateInfo pipeline_shader_stage_create_info(VkShaderStageFlagBits stage,
																	  VkShaderModule shaderModule,
																	  const char *entry = "main");

	VkPipelineLayoutCreateInfo pipeline_layout_create_info();

	VkRenderingAttachmentInfo depth_attachment_info(VkImageView view,
													VkImageLayout layout /*= VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL*/);

} // namespace vkinit
