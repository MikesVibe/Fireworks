#pragma once
#include "Particle.h"

class App
{
public:
    App();

    void update();
    void updateWindowEvents();
    void render();

private:
    sf::RenderWindow window;
    sf::Event event;
    Particle particle;

    void run();
};

