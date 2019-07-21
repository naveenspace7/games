#pragma once

// Original shapes
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// Game includes
#include "item.hpp"
// #include "game.hpp"
#include "components.hpp"


namespace game {

    class Game;
    class Ball;
    class Brick;
    class Base;

    class Base: public Item, public sf::RectangleShape {
        private:
        const int MOVEMENT = 10;
        public:
        void update();
        void right();
        void left();
        Base(float x, float y, float width, float height);
    };
    
    class Ball: public Item, public sf::CircleShape {
        private:
        const float MOTION = 0.2;
        TwoDim m_motionVector;
        public:
        Ball(float x, float y, float radius);
        void update(Game *game);
        bool isCollision();
        void deflectUpdate(Game *game);
        bool checkCollision(Base *targetShape);
        std::pair<bool,bool> checkWallCollision(Game *game);
    };

    class Brick: public Item, public sf::RectangleShape {
        private:
        bool m_present = true;
        public:
        Brick(float x, float y, float width, float height);
    };

}