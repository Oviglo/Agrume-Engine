set(SDL2_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2/lib")
set(SDL2_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2/include")

set(SDL2_IMAGE_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2_image/lib")
set(SDL2_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2_image/include")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS}
)

target_link_libraries(
  ${PROJECT_NAME} 
  ${SDL2_LIBRARY}/x64/SDL2main.lib 
  ${SDL2_LIBRARY}/x64/SDL2.lib
  ${SDL2_IMAGE_LIBRARY}/x64/SDL2_image.lib
)