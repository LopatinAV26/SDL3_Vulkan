find_package(Vulkan REQUIRED)

# vkbootstrap ---------------------------------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/Third_party/vkbootstrap")
add_library(vkbootstrap STATIC)

file(GLOB_RECURSE SRC_FILES vkbootstrap/*.cpp CMAKE_CONFIGURE_DEPENDS)
target_sources(vkbootstrap PRIVATE ${SRC_FILES})

target_include_directories(vkbootstrap PUBLIC vkbootstrap)
target_link_libraries(vkbootstrap PUBLIC Vulkan::Vulkan $<$<BOOL:UNIX>:${CMAKE_DL_LIBS}>)
set_property(TARGET vkbootstrap PROPERTY CXX_STANDARD 23)
#-------------------------------------------------------------------------------------------

# SDL --------------------------------------------------------------------------------------
find_package(SDL3 CONFIG REQUIRED)	#Пока не подключена локально, требуется для imgui
#add_library(sdl3 INTERFACE)
#target_include_directories(sdl3 INTERFACE $ENV{VULKAN_SDK}/Include/SDL3 )
#target_link_directories(sdl3 INTERFACE $ENV{VULKAN_SDK}/Lib )
#target_link_libraries(sdl3 INTERFACE SDL3 SDL3main)
#---------------------------------------------------------------------------------------------

# imgui --------------------------------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/Third_party/imgui")
add_library(imgui STATIC)

file(GLOB_RECURSE SRC_FILES imgui/*.cpp CMAKE_CONFIGURE_DEPENDS)
target_sources(imgui PRIVATE ${SRC_FILES})

target_include_directories(imgui PUBLIC imgui)
target_link_libraries(imgui PUBLIC Vulkan::Vulkan SDL3::SDL3)
# imgui -----------------------------------------------------------


add_library(stb_image INTERFACE)
target_include_directories(stb_image INTERFACE stb_image)

add_subdirectory(fastgltf)

#add_library(glm INTERFACE)
#add_library(vma INTERFACE)

#add_subdirectory(SDL EXCLUDE_FROM_ALL)

#both vma and glm and header only libs so we only need the include path
#target_include_directories(vma INTERFACE vma)

#target_include_directories(glm INTERFACE glm)

