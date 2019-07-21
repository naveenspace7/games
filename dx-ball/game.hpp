#pragma once

#include <string>
#include <utility>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "item.hpp"
#include "components.hpp"

namespace game {

    enum class g_event_t {
        right,
        left
    };

    class Game {

        private:
        public:
        std::string m_title;
        TwoDim m_dimension;
        Ball *m_ball;
        std::vector<Brick*> m_bricks;
        // std::vector<Brick*> m_drawables;
        
        Base *m_base;
        std::vector<Base*> m_bases;
        static bool isInFrame(sf::Vector2f point);
        sf::RenderWindow m_windowHandle;
        Game(int width, int height, std::string title);
        TwoDim getDimension();
        const int getWidth();
        const int getHeight();
        void addBase();
        void addBrick();
        void addBall();

        void init();
        void input();
        void update();
        void draw();
        void Run();

        void eventRight();
        void eventLeft();
        void eventTrigger(g_event_t eventHandler);
        ~Game();

    };
}