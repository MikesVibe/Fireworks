#include "stdafx.h"
#include "Particle.h"

Particle::Particle(sf::Vector2f position, sf::Color color)
	: position(position)
{
	this->initVaraibles();

	//Give the particle random velocity vector
	this->velocity = vl::random2D();
	vl::VectorMulA(this->velocity, (static_cast<float>(rand() % 300 + 100) / 100.f));



	//Set shape's parameters
	this->shape.setRadius(3.f);
	this->shape.setFillColor(color);
	this->shape.setPosition(this->position);
}

Particle::Particle(sf::Vector2f position, sf::Vector2f velocity)
	: position(position), velocity(velocity)
{

	this->initVaraibles();


	//Randomize color of a particle
	sf::Color color;
	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;

	//Set shape's parameters
	this->shape.setRadius(9.f);
	this->shape.setFillColor(color);
	this->shape.setPosition(this->position);
}

Particle::~Particle()
{
}

const sf::Vector2f& Particle::getPosition() const
{
	return this->position;
}

const sf::Vector2f& Particle::getVelocity() const
{
	return this->velocity;
}

const sf::Color& Particle::getColor() const
{
	return this->shape.getFillColor();
}

void Particle::setImmortal(bool immortal)
{
	this->immortal = immortal;
}

void Particle::applyForce(sf::Vector2f force)
{
	this->acceleration = force;
}

void Particle::addResistance(float resistance)
{
	this->velocity.x = this->velocity.x * resistance / 100.f;
	this->velocity.y = this->velocity.y * resistance / 100.f;
}

void Particle::die()
{
	this->isDead = true;
}

void Particle::update(float dt)
{
	if (!this->isDead)
	{
		if (!immortal)
		{
			if (this->lifetime >= this->timeToLive)
			{
				this->die();
			}
			this->lifetime = clock.getElapsedTime().asSeconds();

		}
		

		this->acceleration *= dt;

		vl::VectorAddToA(this->velocity, this->acceleration);
		vl::VectorAddToA(this->position, this->velocity);
		this->shape.setPosition(this->position);
	}
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!this->isDead)
	{
		target.draw(this->shape);
	}
}

void Particle::initVaraibles()
{
	this->acceleration = sf::Vector2f(0.f, 0.f);

	this->immortal = false;
	this->isDead = false;
	this->lifetime = 0.f;
	this->timeToLive = static_cast<float>(rand() % 300) / 100.f;


}
