#pragma once
class Particle : public sf::Drawable
{
public:
	Particle();
	~Particle();


	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f velocity;


};

