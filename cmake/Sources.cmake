include_directories(
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/external"
)

target_sources(${PROJECT_NAME}
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/external/nlohmann/json.hpp"
)

target_sources(${PROJECT_NAME}
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Agrume.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Event/Event.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Event/Event.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/IO/File.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/IO/JsonFile.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/IO/Resource.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Time/Clock.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Math/Vector2D.hpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Module/Renderer/Renderer.hpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLRenderer.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLEvent.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLClock.hpp"

        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Agrume.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Event/Event.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/IO/File.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/IO/JsonFile.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/IO/Resource.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Time/Clock.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Math/Vector2D.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Module/Renderer/Renderer.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLRenderer.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLEvent.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/Thirdparty/SDL/SDLClock.cpp"
)