#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>

class Pipe {
private:
    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;
    float speed = 3.0f;
    bool passed = false;
    
public:
    Pipe(float xPos);
    void update();
    bool isOffScreen() const;
    void render(sf::RenderWindow& window);
    bool checkCollision(const sf::FloatRect& birdBounds);
    bool isPassed() const;
    void markPassed();
};

#endif //PIPE_H
