#project(EngineSDL3 VERSION 0.0.1)
#project(SDL3_Vulkan VERSION 0.1.0 LANGUAGES CXX)

# get all .cpp-files
file(GLOB_RECURSE SRC_FILES source/*.cpp CMAKE_CONFIGURE_DEPENDS)
add_executable(${PROJECT_NAME} ${SRC_FILES})

if(MSVC)
    if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
        add_definitions(/MP)				# parallelize each target, unless Ninja is the generator
    endif()
endif()

#if (UNIX)
find_package(SDL3 CONFIG REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glslang CONFIG REQUIRED)
find_package(VulkanMemoryAllocator CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3
                                               Vulkan::Vulkan
                                               glslang::glslang
                                               glslang::glslang-default-resource-limits
                                               glslang::SPIRV glslang::SPVRemapper
                                               GPUOpen::VulkanMemoryAllocator
                                               fmt::fmt
                                               glm::glm)   # If using satelite libraries, SDL must be the last item in the list

#endif (UNIX)

target_link_libraries(${PROJECT_NAME} PUBLIC vkbootstrap imgui stb_image fastgltf::fastgltf)