cmake_minimum_required(VERSION 3.9)
project(DormEngine)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp CoreEngine.cpp CoreEngine.h Game.cpp Game.h Window.h Window.cpp utility/Log.h utility/Log.cpp RenderingEngine.cpp RenderingEngine.h Mesh.h Mesh.cpp Vertex.h Vertex.cpp Shader.h Shader.cpp GameObject.cpp GameObject.h components/GameComponent.cpp components/GameComponent.h Texture.cpp Texture.h resource_management/ResourceManager.cpp resource_management/ResourceManager.h resource_management/ShaderLoader.cpp resource_management/ShaderLoader.h utility/SID.h resource_management/TextureLoader.cpp resource_management/TextureLoader.h dependencies/stb_image.h dependencies/stb_image.cpp Transform.cpp Transform.h math/Matrix4f.cpp math/Matrix4f.h MyGame.cpp MyGame.h components/MeshRenderer.cpp components/MeshRenderer.h Material.cpp Material.h components/Camera.cpp components/Camera.h math/Vector3f.cpp math/Vector3f.h math/Vector2f.cpp math/Vector2f.h math/Quaternion.cpp math/Quaternion.h Input.h Input.cpp components/DirectionalLight.cpp components/DirectionalLight.h components/BaseLight.cpp components/BaseLight.h resource_management/MeshLoader.cpp resource_management/MeshLoader.h components/PointLight.cpp components/PointLight.h ProjectHeaders.h components/SpotLight.cpp components/SpotLight.h MappedValues.cpp MappedValues.h Framebuffer.cpp Framebuffer.h components/FreeMove.cpp components/FreeMove.h components/FreeLook.cpp components/FreeLook.h)

add_executable(DormEngine ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -L/usr/local/lib -I/usr/include/freetype2 -I/usr/include/libdrm -lGLEW -lGL
        -lfreetype -lz -lm -lglfw -lrt -ldl -lXrandr -lXxf86vm -lXext  -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lassimp -lstdc++)