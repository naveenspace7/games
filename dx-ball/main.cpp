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

    gameHandle.addBrick();

    sf::RectangleShape shape(sf::Vector2f(2,2));

    // shape.move()

    // rshape.setFillColor(sf::Color::Green);
    // shape.setFillColor(sf::Color::Green);

    while (gameHandle.m_windowHandle.isOpen()) {

        gameHandle.input();
        
        gameHandle.m_windowHandle.clear();
        gameHandle.update();
        gameHandle.draw();

        gameHandle.m_windowHandle.display();
    }
}