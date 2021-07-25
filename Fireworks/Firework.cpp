#include "stdafx.h"
#include "Firework.h"

Firework::Firework()
{
	this->startingVelocity = sf::Vector2f(0.f, -13.2f);
	this->gravityForce = sf::Vector2f(0.f, 10.f);


	this->mainParticle = new Particle(sf::Vector2f(500.f, 970.f), this->startingVelocity);
	this->mainParticle->setImmortal(true);

	this->subParticles.reserve(300);
}

Firework::Firework(sf::Vector2f startPos, float maxHeight, float maxRadius)
	: maxHeight(maxHeight), maxRadius(maxRadius)
{
	this->startingVelocity = sf::Vector2f(0.f, -13.2f);
	this->gravityForce = sf::Vector2f(0.f, 10.f);

	this->mainParticle = new Particle(startPos, this->startingVelocity);
	this->mainParticle->setImmortal(true);

	this->subParticles.reserve(300);
}

Firework::~Firework()
{
}

void Firework::applyForces()
{
	//Apply gravity to body of rocket
	if (this->mainParticle != NULL)
		this->mainParticle->applyForce(this->gravityForce);


	//Apply air resistance to subParticles of recket
	for (auto particle : subParticles)
	{
		particle->addResistance(99.8f);
	}
}

void Firework::update(float dt)
{
	this->applyForces();

	if (this->mainParticle != NULL)
		this->mainParticle->update(dt);

	for (auto particle : subParticles)
	{
		particle->update(dt);
	}


	//Explosion of firework
	if(mainParticle != NULL)
		if (this->mainParticle->getVelocity().y >= 0.f)
			this->explode();
}

void Firework::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(this->mainParticle != NULL)
		target.draw(*this->mainParticle);

	for (auto particle : subParticles)
	{
		target.draw(*particle);
	}
}

void Firework::explode()
{
	for (int i = 0; i < this->subParticles.capacity(); i++)
	{
		this->subParticles.emplace_back(
			new Particle(
				this->mainParticle->getPosition(),
				this->mainParticle->getColor()
			));
	}
	delete this->mainParticle;
	this->mainParticle = NULL;
}
