#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

class Bird {
private:
    sf::Sprite sprite;
    sf::Texture texture{};
    float velocity = 0.0f;
    const float gravity = 0.25f;
    const float jumpVelocity = -7.0f;

public:
    Bird();
    void update();
    void jump();
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
};

#endif // BIRD_H