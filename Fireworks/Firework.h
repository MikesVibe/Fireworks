#pragma once
#include "Particle.h"

class Firework : public sf::Drawable
{
public:
	Firework();
	~Firework();

	void applyForces();
	void update(float dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	Particle* mainParticle;
	std::vector<Particle*> subParticles;
	sf::Vector2f airResistanceForce;
	sf::Vector2f gravityForce;


	void explode();
};

