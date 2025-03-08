#include "Bird.h"

Bird::Bird(sf::RenderWindow& window) 
: texture(ROOT_DIR "assets/bird.png")
, sprite(texture)
, gravity(GRAVITY)
, velocity(0)
, rotation(0)
, isJumping(false)
, isFalling(false)
, alive(true)
{
    sprite.setScale({ 0.1f, 0.1f });
    sprite.setPosition({ 100, 300 });
    sprite.setOrigin(sprite.getGlobalBounds().getCenter());
}

void Bird::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
