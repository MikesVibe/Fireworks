#include "stdafx.h"
#include "App.h"


App::App()
{
    this->window.create(sf::VideoMode(1000, 1000), "SFML works!");
    

    this->run();
}

void App::update()
{
   
    this->updateWindowEvents();
}

void App::updateWindowEvents()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void App::render()
{
    window.clear();
    window.draw(particle);
    window.display();
}

void App::run()
{
    while (this->window.isOpen())
    {
        this->update();
        this->render();
    }
}
