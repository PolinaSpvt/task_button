#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    Button();
    void setHoverEffect(bool hover);

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape shape;
    bool hovered = false;
    float animationProgress = 0.0;
    sf::Vector2f originalSize;
    sf::Vector2f originalPosition;
    sf::Clock animationClock;
};
