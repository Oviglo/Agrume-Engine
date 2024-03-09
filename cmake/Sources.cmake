include_directories(
    "${CMAKE_SOURCE_DIR}/src"
)

target_sources(${PROJECT_NAME}
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Agrume.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Event/Event.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Math/Vector2D.hpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Module/Renderer/Renderer.hpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLRenderer.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLEvent.hpp"

        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Agrume.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Event/Event.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Math/Vector2D.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Module/Renderer/Renderer.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLRenderer.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLEvent.cpp"
)
