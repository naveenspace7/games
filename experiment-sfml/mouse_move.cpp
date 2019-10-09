#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Title Here");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rshape(sf::Vector2f(100, 50));
    // rshape.setFillColor(sf::Color::Green);
    // shape.setFillColor(sf::Color::Green);

    window.setFramerateLimit(100);

    sf::Vector2i mouse_position = sf::Mouse::getPosition();

    while (window.isOpen()) {
        
        sf::Event event;

        while (window.pollEvent(event)) {
            if (((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                || (event.type == sf::Event::Closed)) 
            {
                window.close();
            }
            cout << "event type: " << event.type << endl;

            if (event.type == sf::Event::MouseMoved) {
                mouse_position = sf::Mouse::getPosition();
                cout << "x: " << mouse_position.x << " and y: " << mouse_position.y << endl;
            }
        }

        shape.move(1,1);

        window.clear();
        window.draw(shape);
        window.display();
    }
}