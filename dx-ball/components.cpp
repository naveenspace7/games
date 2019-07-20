#include "components.hpp"

using namespace game;
using namespace std;
using namespace sf;

Ball::Ball(float x, float y, float radius): 
    Item(x, y, radius, radius), CircleShape(radius) {
        
    this->setPosition(x,y);
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

