#include "components.hpp"
#include "game.hpp"

#include <iostream>

using namespace game;
using namespace std;
using namespace sf;

Ball::Ball(float x, float y, float radius): 
    Item(x, y, radius, radius), CircleShape(radius) 
{
    this->m_motionVector = make_pair(1,1);
    this->setPosition(x,y);
}

void Ball::update() {
    CircleShape::move(this->m_motionVector.first, this->m_motionVector.second);
}

bool Ball::isCollision() {
    // check collision with the bases
    // check collision with the bottom/top
    // check collision with the sides
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