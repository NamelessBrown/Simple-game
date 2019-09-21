#include "Eatables.h"

void Eatables::initShape(const sf::RenderWindow& window)
{
	this->cShape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	this->cShape.setFillColor(color);
	this->cShape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window.getSize().x - this->cShape.getGlobalBounds().width), 
			static_cast<float>(rand() % window.getSize().y - this->cShape.getGlobalBounds().height))
	);
}

Eatables::Eatables(const sf::RenderWindow& window)
{
	this->initShape(window);
}

Eatables::~Eatables()
{
}

const sf::CircleShape& Eatables::getCircleShape() const
{
	return this->cShape;
}

void Eatables::update()
{
}

void Eatables::render(sf::RenderTarget& target)
{
	target.draw(this->cShape);
}
