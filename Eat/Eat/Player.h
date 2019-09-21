#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <ctime>

class Player
{
private:
	sf::RectangleShape shape;

	float movementSpeed;
	int hp;
	int hpMax;
	int points;

	//Resoruces
	sf::Font font;
	sf::Text uiText;

	void initVariables();
	void initShape();
	void initFont();
	void initText();
public:
	Player(float x = 0.0f, float y = 0.0f);
	virtual ~Player();


	const sf::RectangleShape& getShape() const;


	//fuunctions
	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	bool isDead();

	//Update the player skills
	void updatePoints();
	void updateHp();
	void updateText();
	void updateMovement();

	void renderText(sf::RenderTarget& target);
	void render(sf::RenderTarget* target);
};

