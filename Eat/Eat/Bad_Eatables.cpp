#include "Bad_Eatables.h"

void Bad_Eatables::initConShape(const sf::RenderWindow& window)
{
	this->conShape.setPointCount(3);
	this->conShape.setPoint(0, sf::Vector2f(static_cast<float>(rand() % 70 + 15), static_cast<float>(rand() % 70 + 15)));
	this->conShape.setPoint(1, sf::Vector2f(static_cast<float>(rand() % 70 + 15), static_cast<float>(rand() % 70 + 15)));
	this->conShape.setPoint(2, sf::Vector2f(static_cast<float>(rand() % 70 + 15), static_cast<float>(rand() % 70 + 15)));

	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255);
	this->conShape.setFillColor(color);
	this->conShape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window.getSize().x - this->conShape.getGlobalBounds().width),
			static_cast<float>(rand() % window.getSize().y - this->conShape.getGlobalBounds().height))
	);
}

Bad_Eatables::Bad_Eatables(const sf::RenderWindow& window)
{
	this->initConShape(window);
}

Bad_Eatables::~Bad_Eatables()
{
}

const sf::ConvexShape& Bad_Eatables::getConvexShape() const
{
	return this->conShape;
}

void Bad_Eatables::render(sf::RenderTarget& target)
{
	target.draw(this->conShape);
}
