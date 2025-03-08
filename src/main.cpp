#include "Bird.h"
#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

int main() 
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 900u, 700u }), "Flappy Bird", sf::Style::Default, sf::State::Windowed, settings);
    
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(ROOT_DIR "assets/background.png")) 
    {
        std::cerr << "Error loading background texture" << std::endl;
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    Bird bird(window);
    
    sf::Clock clock{};
    std::vector<std::unique_ptr<Pipe>> pipes;
    float pipeSpawnTimer{ 0.0f };
    const float pipeSpawnInterval{ 2.0f }; // Spawn a pipe every 2 seconds

    while (window.isOpen()) 
    {
        while (const std::optional event{ window.pollEvent() }) 
        {
            if (event->is<sf::Event::Closed>()) 
            {
                window.close();
            }
            bird.handleInput(event);
        }

        const float deltaTime = clock.restart().asSeconds();
        
        bird.update(deltaTime);

        // Spawn pipes at regular intervals
        pipeSpawnTimer += deltaTime;
        if (pipeSpawnTimer >= pipeSpawnInterval) 
        {
            pipes.emplace_back(std::make_unique<Pipe>(window, window.getSize().x, 300.0f));
            pipeSpawnTimer = 0.0f;
        }

        for (auto& pipe : pipes) 
        {
            pipe->update(deltaTime);
        }


        pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [](const std::unique_ptr<Pipe>& pipe) {
            return pipe->isOffScreen();
        }), pipes.end());

        
        for (auto& pipe : pipes) 
        {
            if (pipe->checkCollision(bird.getBounds())) 
            {
                std::cout << "Game Over!" << std::endl;
                window.close();
            }
        } 


        window.clear();
        window.draw(backgroundSprite);
        bird.draw();

        for (const auto& pipe : pipes) 
        {
            pipe->draw();
        }
        
        window.display();
    }

    return 0;
}