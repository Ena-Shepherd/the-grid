/*

 Author: Yannis STEFANELLI

 Creation Date: 26-02-2023 15:46:18

 Description :
 
 Main file

*/

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

int main(void) {

    ContextSettings settings;

    RenderWindow window(VideoMode(1080, 731), "TheGrid", Style::Titlebar | Style::Close, settings);

    auto image = sf::Image{};

    // if (!image.loadFromFile("../sprites/logo.png"))
    //     std::cout << "Icone n'a pas chargé\n";

    // window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    while (window.isOpen())
    {   
        //Event loop
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        //Clearing the window after each draw
        window.clear(Color::Blue);

    
        window.display();
    }
    
    return 0;
}