#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

class Pipe 
{
public:
    Pipe(sf::RenderWindow& window, float posX, float speed = 200);
    void update(const float deltaTime);
    void draw();
    bool isOffScreen() const;
    bool checkCollision(const sf::FloatRect& birdBounds) const;
    float getXPoisition() const;
    bool isPassed(float birdXPosition) const;
    void resetScored();

private:
    sf::RenderWindow& window;
    sf::Texture texture;
    sf::Sprite sprite; 
    float speed{};
    float gapSize{};
    bool scored{};
    float gapY{};
};

#endif // PIPE_H