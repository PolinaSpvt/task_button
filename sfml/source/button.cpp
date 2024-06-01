#include "button.h"

Button::Button() {
    shape.setSize(sf::Vector2f(100, 50));
    shape.setFillColor(sf::Color::Green);
    originalSize = shape.getSize();
    originalPosition = shape.getPosition();
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1.0f);
}

void Button::setHoverEffect(bool hover) {
    hovered = hover;
    animationClock.restart();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Button::update() {
    if (hovered) {
        float time = animationClock.getElapsedTime().asSeconds();
        float progress = time / 3.0f;  //  время перехода цвета 3 секунды

        if (progress < 1.0f) {
            int red = 255 * progress;  // Увеличение красного
            int green = 255 * (1 - progress);  // Уменьшение зеленого
            shape.setFillColor(sf::Color(red, green, 0));
            float scale = 1.0f + progress;  // Шкала от 1 до 2
            shape.setSize(originalSize * scale);
        } else {
            shape.setPosition(rand() % 400, rand() % 300); // Произвольная новая позиция в пределах окна
            hovered = false;  // Сброс статуса зависания после анимации
        }
    } else {
        shape.setFillColor(sf::Color::Green);
        shape.setSize(originalSize);
        shape.setPosition(originalPosition);
    }
}
