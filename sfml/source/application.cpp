#include "application.h"

Application::Application() : window(sf::VideoMode(800, 600), "Button Animation") {
    window.setFramerateLimit(60);
}

void Application::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = button.getGlobalBounds();
            if (bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                button.setHoverEffect(true);
            else
                button.setHoverEffect(false);
        }
    }
}

void Application::update() {
    button.update();
}

void Application::render() {
    window.clear();
    window.draw(button);
    window.display();
}
