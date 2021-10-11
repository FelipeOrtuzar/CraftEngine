#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        //GameEngine::load_window(sizex, sizey)
        // GameEngine::putImageIn(path, x, y)
        sf::Texture texture;
        if (!texture.loadFromFile("C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\imgs\\boo.png"))
        {
            return 1;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();

                // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {   
                        window.close();
                    }
                    
                // we don't process other types of events
                default:
                    break;
            }
        }
        window.clear(sf::Color::Blue);

        
        window.draw(sprite);
        window.display();
    }
    
    return 0;
}