cmake_minimum_required(VERSION 3.9)
project(DormEngine)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp CoreEngine.cpp CoreEngine.h Game.cpp Game.h Window.h Window.cpp Log.h Log.cpp glad.c RenderingEngine.cpp RenderingEngine.h Mesh.h Mesh.cpp Vertex.h Vertex.cpp Shader.h Shader.cpp Util.h GameObject.cpp GameObject.h GameComponent.cpp GameComponent.h res/Texture.cpp res/Texture.h)

add_executable(DormEngine ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -L/usr/local/lib -I/usr/include/freetype2 -lfreetype -lz -lpng12 -lm -lharfbuzz -lglfw3 -lrt -ldl -lXrandr -lXinerama -lXxf86vm -lXext -lXcursor -lXrender -lXfixes -lX11 -lpthread -lxcb -lXau -lassimp -lstdc++)