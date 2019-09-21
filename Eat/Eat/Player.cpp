#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 5.5f;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->points = 0;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.5f, 50.5f));
}

void Player::initFont()
{
	if (!this->font.loadFromFile("fonts/WedgieRegular.ttf"))
	{
		std::cout << "ERROR::PLAYER::INITFONT::Failed to load font...\n";
	}
}

void Player::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(25);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();

	this->initFont();
	this->initText();
}

Player::~Player()
{
}

const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}


//functions
void Player::updateInput()
{
	//keyboard input
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	//Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	//Top
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
}

void Player::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << '\n'
		<< "Heath: " << this->hp;

	this->uiText.setString(ss.str());
}

void Player::updateMovement()
{
	if (points > 50)
	{
		this->movementSpeed = 7.5f;
	}
}

void Player::update(const sf::RenderTarget* target)
{

	this->updateInput();

	//Window bounds collions
	this->updateWindowBoundsCollision(target);

	this->updateMovement();

	this->updateText();

}

bool Player::isDead()
{
	if (this->hp >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::updatePoints()
{
	this->points++;
}

void Player::updateHp()
{
	this->hp -= 2;
}

void Player::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
