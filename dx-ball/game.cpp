#include "game.hpp"

using namespace game;
using namespace sf;

Game::Game(int width = 1000, int height = 1000, std::string title = "Hello World"):
    m_windowHandle(VideoMode(width, height), m_title),
    m_title(title) {
    
    m_dimension = std::make_pair(width, height);
    // m_windowHandle = new RenderWindow(sf::VideoMode(m_dimension.first, m_dimension.second), m_title);
}

const int Game::getWidth() {
    return m_windowHandle.getSize().x;
}

const int Game::getHeight() {
    return m_windowHandle.getSize().y;
}