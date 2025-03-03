#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bird.h"
#include "Pipe.h"

class Game {
private:
    sf::RenderWindow window;
    Bird bird;
    std::vector<Pipe> pipes;
    sf::Font font;
    sf::Text scoreText;
    int score;
    int frameCount;
    bool gameOver;

public:
    Game();
    void run();
    void handleEvents();
    void update();
    void render();
    void restart();
};

#endif //GAME_H