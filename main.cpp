#include <iostream>
#include "CoreEngine.h"
#include "MyGame.h"

int main() {
    CoreEngine engine(800, 600, 300, new MyGame);
    engine.createWindow("DormEngine");
    engine.start();
    return 0;
}