#include "game.hpp"

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

    m_windowHandle.draw(*m_base);
    m_windowHandle.draw(*m_ball);
    // m_windowHandle.draw(m_ball);
}

Game::~Game() {

}

