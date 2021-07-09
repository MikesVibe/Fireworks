#pragma once
#include "Firework.h"

class App
{
public:
    //Constructors & Destructors
    App();

    //Accessors
    const bool& getKeytime();


    //functions
    void updateDt();
    void updateKeytime();
    void updateWindowEvents();
    void update();
    void render();

private:
    //Private functions
    void initVariables();
    void initWindow();

    void run();

    //Application stuff
    sf::RenderWindow window;
    sf::Event event;
    sf::Clock dtClock;
    float dt;

    //Logic
    std::vector<Firework*> fireworks;
    int maxFireworks;
    float keytime;
    float keytimeMax;

};

