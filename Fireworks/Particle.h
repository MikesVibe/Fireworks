#pragma once
#include "vl.h"

struct Color
{
	int R, G, B;

	//R = rand() % 255;
	//G = rand() % 255;
	//B = rand() % 255;
}; 

class Particle : public sf::Drawable
{
public:
	Particle(sf::Vector2f position, sf::Color color);
	Particle(sf::Vector2f position, sf::Vector2f velocity);
	~Particle();

	//Accessors
	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getVelocity() const;
	const sf::Color& getColor() const;

	//Modifiers
	void setImmortal(bool immortal);

	//Functions
	void applyForce(sf::Vector2f force);
	void addResistance(float resistance);
	void die();

	void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	//Private Functions
	void initVaraibles();

	//Varaibles
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Clock clock;
	float timeToLive;
	float lifetime;
	bool isDead;
	bool immortal;

};

