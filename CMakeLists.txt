cmake_minimum_required(VERSION 3.9)
project(DormEngine)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp CoreEngine.cpp CoreEngine.h Game.cpp Game.h Window.h Window.cpp utility/Log.h utility/Log.cpp glad.c RenderingEngine.cpp RenderingEngine.h Mesh.h Mesh.cpp Vertex.h Vertex.cpp Shader.h Shader.cpp GameObject.cpp GameObject.h GameComponent.cpp GameComponent.h Texture.cpp Texture.h resource_management/ResourceManager.cpp resource_management/ResourceManager.h resource_management/ShaderLoader.cpp resource_management/ShaderLoader.h utility/SID.h resource_management/TextureLoader.cpp resource_management/TextureLoader.h stb_image.h stb_image.cpp Transform.cpp Transform.h Matrix4f.cpp Matrix4f.h MyGame.cpp MyGame.h components/MeshRenderer.cpp components/MeshRenderer.h Material.cpp Material.h resource_management/SimpleMeshLoader.cpp resource_management/SimpleMeshLoader.h)

add_executable(DormEngine ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -L/usr/local/lib -I/usr/include/freetype2 -lfreetype -lz -lpng12 -lm -lharfbuzz -lglfw3 -lrt -ldl -lXrandr -lXinerama -lXxf86vm -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lassimp -lstdc++)