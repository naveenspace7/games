#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "Title Here");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rshape(sf::Vector2f(100, 50));
    rshape.setFillColor(sf::Color::Green);
    // shape.setFillColor(sf::Color::Green);

    // window.setFramerateLimit

    while (window.isOpen()) {
        
        sf::Event event;

        while (window.pollEvent(event)) {
            if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                || (event.type == sf::Event::Closed)) 
            {
                window.close();
            }
            cout << "event type: " << event.type << endl;
        }

        window.clear();
        window.draw(rshape);
        window.display();
    }
}