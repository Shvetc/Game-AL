#include <stdio.h>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
class Player{
    sf::RectangleShape square; // форма квадрата
    int x;
    int y;
public:
    Player()
    {
        this->square.setSize(sf::Vector2f(50,50));
        this->square.setFillColor(sf::Color::Green);
    }
   
    void handle(sf::Event&  event)
    {
           
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
             {
               
                square.move(0,-1);
                //std::cout << "MouseButtonPressed\n";
             }
             if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
             {
                
                  square.move(0,1);
             }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
             {   
                  square.move(1,0);
             }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
             {    
                  square.move(-1,0);
             }

        
    }

    sf::RectangleShape& get_shape()
    {
        return square;
    }


};