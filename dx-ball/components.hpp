#pragma once

// Original shapes
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// Game includes
#include "item.hpp"

namespace game {
    
    class Ball: public Item, public sf::CircleShape {
        private:
        TwoDim m_motionVector;
        public:
        Ball(float x, float y, float radius);
        void update();
        bool isCollision();
    };

    class Brick: public Item, public sf::RectangleShape {
        private:
        bool m_present = true;
        public:
        Brick(float x, float y, float width, float height);
    };

    class Base: public Item, public sf::RectangleShape {
        private:
        const int MOVEMENT = 10;
        public:
        void update();
        void right();
        void left();
        Base(float x, float y, float width, float height);
    };
}