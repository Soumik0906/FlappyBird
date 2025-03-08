#include "Bird.h"

Bird::Bird(sf::RenderWindow& window) 
: window(window)
, texture(ROOT_DIR "assets/bird.png")
, sprite(texture)
, gravity(GRAVITY)
, velocity(0)
, rotation(sf::degrees(0))
, isJumping(false)
, isFalling(false)
, alive(true)
{
    texture.setSmooth(true);
    sprite.setScale({ 0.05f, 0.05f });
    sprite.setOrigin(sprite.getGlobalBounds().getCenter());
    sprite.setPosition({ 50, 200 });
}

void Bird::jump() 
{
    if (alive) 
    {
        velocity = JUMP_VELOCITY;
        isJumping = true;
        isFalling = false;
    }
}

void Bird::updateRotation(const float deltaTime) 
{
    using namespace sf::Literals;
    if (velocity < 0) 
    {
        rotation -= ROTATION_SPEED * deltaTime;
        if (rotation < -30_deg) 
        {
            rotation = -30_deg;
        }
    }
    else if (velocity > 0) 
    {
        rotation += ROTATION_SPEED * deltaTime;
        if (rotation > 60_deg) 
        {
            rotation = 60_deg;
        }
    }

    sprite.setRotation(rotation);
}

void Bird::update(const float deltaTime) 
{
    if (alive) 
    {
        velocity += gravity * deltaTime;
        sprite.move({ 0, velocity * deltaTime });

        if (velocity > 0) 
        {
            isJumping = false;
            isFalling = true;
        }
        else if (velocity < 0) 
        {
            isJumping = true;
            isFalling = false;
        }
        updateRotation(deltaTime);
    }
}

void Bird::draw() 
{ 
    if (alive) 
    {
        window.draw(sprite);
    }
}

sf::FloatRect Bird::getBounds() 
{ 
    return sprite.getGlobalBounds(); 
}

void Bird::reset() 
{
    velocity = 0;
    rotation = sf::degrees(0);
    isJumping = false;
    isFalling = false;
    alive = true;
    sprite.setPosition({ 100, 200 });
    sprite.setRotation(rotation);
}

void Bird::handleInput(const std::optional<sf::Event>& event) 
{
    if (event.has_value()) 
    {
        if (event->is<sf::Event::KeyPressed>()) 
        {
            if (event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scan::Space) 
            {
                jump();
            }
        } 
    }
}