#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    //sf::CircleShape shape(50.f);
   // shape.setFillColor(sf::Color::Red);
    //shape.setPosition(250,250);
    Player player;

    while (window.isOpen())
    {
       sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
            player.handle(event);
           
             
        }


        window.clear();
        window.draw(player.get_shape());
        window.display();
    }

    return 0;
}