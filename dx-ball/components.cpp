#include "components.hpp"
#include "game.hpp"

#include <iostream>

using namespace game;
using namespace std;
using namespace sf;

Ball::Ball(float x, float y, float radius): 
    Item(x, y, radius, radius), CircleShape(radius) 
{
    this->m_motionVector = make_pair(MOTION, MOTION);
    this->setPosition(x,y);
}

void Ball::update(Game *game) {
    deflectUpdate(game);
    CircleShape::move(this->m_motionVector.first, this->m_motionVector.second);
}

void Ball::deflectUpdate(Game *game) {
    
    // check collision with the bases
    for(Base* base: game->m_bases) {
        if (this->checkCollision(base)) {
            if (base->getPosition().y > game->getHeight()/2)
                m_motionVector.second = -MOTION;
            else
                m_motionVector.second = MOTION;
        }
    }

    // check collision with the sides
    std::pair<bool, bool> collision_result = checkWallCollision(game);
    if (collision_result.first)
        m_motionVector.first = MOTION;
    else if (collision_result.second)
        m_motionVector.first = -MOTION;


    // check collision with the bottom/top
}

// bool Ball::checkWallCollision(Game *game) {

//     // game->getWidth()
//     sf::Rect<int> bounds(0, game->getHeight(), game->getWidth(), 4);
//     sf::Rect<int> ballShape(getPosition().x, getPosition().y, m_dimension.first, m_dimension.second);

//     bool didIntersect = bounds.intersects(ballShape);
//     cout << "bool: " << didIntersect << endl;
//     return didIntersect;
// }

std::pair<bool,bool> Ball::checkWallCollision(Game *game) {

    bool intersect_left = false, intersect_right = false;
    sf::Rect<int> ballShape(getPosition().x, getPosition().y, m_dimension.first, m_dimension.second);
     // TODO: create this just once in the beginning
    sf::Rect<int> bounds_right(game->getWidth(), 0, 5, game->getHeight());
    sf::Rect<int> bounds_left(-5, 0, 5, game->getHeight());

    if (bounds_right.intersects(ballShape)) {
        return make_pair(false, true);
    }
    else if (bounds_left.intersects(ballShape)) {
        return make_pair(true, false);
    }
    return make_pair(false, false);
}

bool Ball::checkCollision(Base *targetShape) {
    
    sf::Rect<int> ballShape(getPosition().x, getPosition().y, m_dimension.first, m_dimension.second);
    sf::Rect<int> otherShape(targetShape->getPosition().x, targetShape->getPosition().y, targetShape->m_dimension.first, targetShape->m_dimension.second);

    bool didIntersect = ballShape.intersects(otherShape);

    return didIntersect;
}

Brick::Brick(float x, float y, float width, float height):
    Item(x, y, width, height), RectangleShape(Vector2f(width, height))
{
    this->setPosition(x,y);
}

Base::Base(float x, float y, float width, float height):
    Item(x, y, width, height), RectangleShape(Vector2f(width, height))
{
    this->setPosition(x,y);
}

void Base::right() {

    Vector2f x1(getPosition().x + Item::m_dimension.first, getPosition().y);
    if (Game::isInFrame(x1))
        move(MOVEMENT, 0);
}

void Base::left() {
    if (Game::isInFrame(getPosition()))
        move(-MOVEMENT, 0);
}

void Base::update() {
}