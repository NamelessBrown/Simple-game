#pragma once

#include <SFML/Graphics.hpp>

class Eatables
{
private:
	sf::CircleShape cShape;

	void initShape(const sf::RenderWindow& window);

public:
	Eatables(const sf::RenderWindow& window);
	virtual ~Eatables();

	const sf::CircleShape& getCircleShape() const;

	void update();
	void render(sf::RenderTarget& target);
};

