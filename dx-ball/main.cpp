#include <SFML/Graphics.hpp>
#include <iostream>

#include "components.hpp"
#include "item.hpp"
#include "game.hpp"

using namespace game;

// Test code
int main() {
    
    Game gameHandle(1000, 1000, "hello");

    gameHandle.addBase();
    gameHandle.addBall();

    // rshape.setFillColor(sf::Color::Green);
    // shape.setFillColor(sf::Color::Green);

    while (gameHandle.m_windowHandle.isOpen()) {
        
        sf::Event event;

        while (gameHandle.m_windowHandle.pollEvent(event)) {
            if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                || (event.type == sf::Event::Closed)) 
            {
                gameHandle.m_windowHandle.close();
            }
        }

        gameHandle.m_windowHandle.clear();
        gameHandle.draw();
        // gameHandle.m_windowHandle.draw(shape);
        // gameHandle.m_windowHandle.draw(brick_shape);
        // gameHandle.m_windowHandle.draw(paddle_shape);
        gameHandle.m_windowHandle.display();
    }
}