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
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void App::update()
{
    this->updateKeytime();
    this->updateWindowEvents();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
    {
        this->fireworks.emplace_back(new Firework());
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
    this->window.create(sf::VideoMode(1000, 1000), "SFML works!");
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
