#include <iostream>
#include "CoreEngine.h"

int main() {
    Game game;
    CoreEngine engine(800, 600, 60, game);
    engine.createWindow("DormEngine");
    engine.start();
    return 0;
}