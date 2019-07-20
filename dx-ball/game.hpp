#include <string>
#include <utility>

#include <SFML/Graphics/RenderWindow.hpp>

#include "item.hpp"

namespace game {

    class Game {

        private:
        std::string m_title;
        TwoDim m_dimension;
        
        public:
        sf::RenderWindow m_windowHandle;
        Game(int width, int height, std::string title);
        TwoDim getDimension();
        const int getWidth();
        const int getHeight();
    };
}