#pragma once

#include <SFML/Graphics.hpp>

class Bad_Eatables
{
private:
	sf::ConvexShape conShape;

	void initConShape(const sf::RenderWindow& window);
public:
	Bad_Eatables(const sf::RenderWindow& window);
	virtual ~Bad_Eatables();

	//gets the shape for collion
	const sf::ConvexShape& getConvexShape() const;

	//renders the the screen
	void render(sf::RenderTarget& target);
};

