#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird(sf::RenderWindow &window);
    void jump();
    void update();
    void draw(sf::RenderWindow &window);
    sf::FloatRect getBounds();
    void reset();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float gravity{};
    float velocity{};
    float rotation{};
    bool isJumping{};
    bool isFalling{};
    bool alive{};

    static constexpr float GRAVITY{ 9.8f };
    static constexpr float JUMP_VELOCITY{ -5.0f };
};

#endif // BIRD_H