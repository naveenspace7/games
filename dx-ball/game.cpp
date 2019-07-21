#include "game.hpp"

#include <iostream>

using namespace game;
using namespace sf;

Game::Game(int width, int height, std::string title):
    m_windowHandle(VideoMode(width, height), title),
    m_title(title) {
    
    m_dimension = std::make_pair(width, height);
}

const int Game::getWidth() {
    return m_windowHandle.getSize().x;
}

const int Game::getHeight() {
    return m_windowHandle.getSize().y;
}

void Game::addBase() {
    const int BASE_HEIGHT = 20, BASE_WIDTH = 70 ;
    m_base = new Base(getWidth()/2 - BASE_WIDTH/2, getHeight() - BASE_HEIGHT, BASE_WIDTH, BASE_HEIGHT);

    m_bases.push_back(new Base(getWidth()/2 - BASE_WIDTH/2, getHeight() - BASE_HEIGHT, BASE_WIDTH, BASE_HEIGHT));
    m_bases.push_back(new Base(getWidth()/2 - BASE_WIDTH/2, BASE_HEIGHT, BASE_WIDTH, BASE_HEIGHT));

    // m_drawables.push_back(&m_base);
}

void Game::addBall() {
    const int RADIUS = 10;
    m_ball = new Ball(getWidth()/2 - RADIUS, getHeight()/2 - RADIUS, RADIUS);
}

void Game::draw() {
    // for (const Brick &each_brick: m_bricks) {
    //     m_windowHandle.draw(each_brick);
    // }

    for (const Base *each_base: m_bases) {
        m_windowHandle.draw(*each_base);
    }

    // m_windowHandle.draw(*m_base);
    m_windowHandle.draw(*m_ball);
    // m_windowHandle.draw(m_ball);
}

void Game::addBrick() {

    // int rows = 1, columns = 5;

    // int width = getWidth()/columns;

    // m_bricks.push_back(new Brick());
}

void Game::update() {
    m_ball->update();
    m_bases[0]->update();
    m_bases[1]->update();
}

Game::~Game() {

}

void Game::input() {
    Event event;

    while (m_windowHandle.pollEvent(event)) {

        if(event.type == sf::Event::Closed) 
                m_windowHandle.close();

        if (event.type == Event::KeyPressed) {

            switch (event.key.code) {

                case Keyboard::Escape:
                    m_windowHandle.close();
                    break;

                case Keyboard::Right:
                    eventTrigger(g_event_t::right);
                    break;
                    
                case Keyboard::Left:
                    eventTrigger(g_event_t::left);
                    break;
            }
        }

    }
}

void Game::eventTrigger(g_event_t event) {
    switch(event) {
        case g_event_t::right:
            eventRight();
            break;
        case g_event_t::left:
            eventLeft();
            break;
    }
}

// void Game::Run() {

//      while (m_windowHandle.isOpen()) {
        
//         Event event;

//         while (m_windowHandle.pollEvent(event)) {
            

//         }

//         gameHandle.m_windowHandle.clear();
//         gameHandle.update();
//         gameHandle.draw();

//         // gameHandle.
//         // gameHandle.m_windowHandle.draw(shape);
//         // gameHandle.m_windowHandle.draw(brick_shape);
//         // gameHandle.m_windowHandle.draw(paddle_shape);
//         gameHandle.m_windowHandle.display();
//     }
// }

void Game::eventRight() {
    m_bases[0]->right();
    m_bases[1]->right();
}

void Game::eventLeft() {
    m_bases[0]->left();
    m_bases[1]->left();
}

bool Game::isInFrame(Vector2f point) {
    if (point.x <= 1000 && point.y <= 1000 && point.x >= 0 && point.y >= 0)
        return true;
    return false;
}