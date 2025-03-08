#include <SFML/Graphics.hpp>

#include "Bird.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1920u, 1080u }), "Flappy Bird");
    Bird bird(window);
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::White);
        bird.draw(window);
        window.display();
    }
    return 0;
}