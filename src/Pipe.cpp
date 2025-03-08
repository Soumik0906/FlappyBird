#include "Pipe.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Pipe::Pipe(sf::RenderWindow& window, float posX, float speed)
: window(window), texture(), sprite(texture), speed(speed), scored(false)
{
    if (!texture.loadFromFile(ROOT_DIR "assets/pipe.png")) {
        std::cerr << "Error loading pipe texture" << std::endl;
        return; 
    }

    gapSize = 250.0f + static_cast<float>(rand() % 101);

    float windowHeight = static_cast<float>(window.getSize().y);
    float minGapY = 100.0f;
    float maxGapY = windowHeight - gapSize - minGapY;
    gapY = minGapY + (rand() % static_cast<int>(maxGapY - minGapY));

    sprite.setTexture(texture);
    sprite.setPosition({posX, 0});
}

void Pipe::update(const float deltaTime)
{
    sprite.move({ -speed * deltaTime, 0 });
}

void Pipe::draw() 
{
    float pipeHeight = static_cast<float>(texture.getSize().y);
    float pipeX = sprite.getPosition().x;

    sf::Sprite topPipe(texture);
    topPipe.setOrigin({ 0, pipeHeight });
    topPipe.setPosition({ pipeX, gapY - gapSize });
    topPipe.setScale({ 0.5f, -0.5f });
    window.draw(topPipe);

    sf::Sprite bottomPipe(texture);
    bottomPipe.setPosition({ pipeX, gapY + gapSize });
    bottomPipe.setScale({ 0.5f, 0.5f });
    window.draw(bottomPipe);
}

bool Pipe::isOffScreen() const 
{
    return sprite.getPosition().x + texture.getSize().x < 0;
}

bool Pipe::checkCollision(const sf::FloatRect& birdBounds) const 
{
    float pipeHeight = static_cast<float>(texture.getSize().y);
    float pipeWidth = static_cast<float>(texture.getSize().x);
    float pipeX = sprite.getPosition().x;

    sf::FloatRect topPipeBounds({ pipeX, gapY - pipeHeight }, { pipeWidth * 0.5f, pipeHeight * 0.5f });
    sf::FloatRect bottomPipeBounds({ pipeX, gapY + gapSize }, { pipeWidth * 0.5f, pipeHeight * 0.5f }); 

    return birdBounds.findIntersection(topPipeBounds) || birdBounds.findIntersection(bottomPipeBounds);
}

