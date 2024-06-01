#pragma once
#include <SFML/Graphics.hpp>
#include "button.h"

class Application {
public:
    Application();
    void run();

private:
    sf::RenderWindow window;
    Button button;
    void processEvents();
    void update();
    void render();
};
