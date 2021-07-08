#include "stdafx.h"
#include "Particle.h"

Particle::Particle()
{
	this->shape.setRadius(30.f);
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setPosition(sf::Vector2f(0.f, 0.f));
	this->velocity = sf::Vector2f(0.f, 0.f);

}

Particle::~Particle()
{
}

void Particle::update()
{
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->shape);
}
