#include "stdafx.h"
#include "App.h"


App::App()
{
    this->initVariables();
    this->initWindow();

    this->fireworks.reserve(this->maxFireworks);

    this->run();
}

const bool& App::getKeytime()
{
    if (this->keytime >= keytimeMax)
    {
        this->keytime = 0.f;
        return true;
    }

    return false;
}

void App::fireworkShow()
{
    const int array_size = 6;

    std::array<sf::Vector2f, array_size> fireworks_show_positions =
    {
        sf::Vector2f(28.f, 1058.f), sf::Vector2f(212.f, 810.f), sf::Vector2f(452.f, 560.f),
        sf::Vector2f(1892.f, 1058.f), sf::Vector2f(1708.f, 810.f), sf::Vector2f(1468.f, 560.f)
        
    };

    for (int i=0; i<array_size; i++)
    {
        this->fireworks.emplace_back(new Firework(fireworks_show_positions[i], 0.f,0.f));

    }

}

void App::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void App::updateKeytime()
{
    this->keytime += this->dt * 10.f;
}

void App::updateWindowEvents()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
    }
}

void App::update()
{
    this->updateKeytime();
    this->updateWindowEvents();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
    {
        //this->fireworks.emplace_back(new Firework());

        this->fireworkShow();
    }

    for (auto firework : fireworks)
    {
        firework->update(dt);

    }
}

void App::render()
{
    window.clear();

    for (auto firework : fireworks)
    {
        window.draw(*firework);
    }

    window.display();
}

void App::initVariables()
{
    this->maxFireworks = 10;
    this->keytimeMax = 3.f;
    this->keytime = 0.f;
}

void App::initWindow()
{
    this->window.create(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Fullscreen);
    this->window.setFramerateLimit(60);
}

void App::run()
{
    while (this->window.isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
