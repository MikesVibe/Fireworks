#pragma once
#include "Particle.h"

class Firework : public sf::Drawable
{
public:
	Firework();
	Firework(sf::Vector2f startPos, float maxHeight, float maxRadius);
	~Firework();

	void applyForces();
	void update(float dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	Particle* mainParticle;
	std::vector<Particle*> subParticles;
	sf::Vector2f startingVelocity;
	sf::Vector2f gravityForce;
	float maxRadius;
	float maxHeight;



	void explode();
};

