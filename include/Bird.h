#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

class Bird 
{
public:
    Bird(sf::RenderWindow &window);
    void jump();
    void update(float deltaTime);
    void draw();
    sf::FloatRect getBounds();
    void reset();
    void handleInput(const std::optional<sf::Event>& event);

private:
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Sprite sprite;
    float gravity{};
    float velocity{};
    sf::Angle rotation{};
    bool isJumping{};
    bool isFalling{};
    bool alive{};

    static constexpr float GRAVITY{ 600.0f };
    static constexpr float JUMP_VELOCITY{ -350.0f };
    static constexpr sf::Angle ROTATION_SPEED{ sf::degrees(200.0f) };

    void updateRotation(float deltaTime);
};

#endif // BIRD_H