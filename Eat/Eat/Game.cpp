#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Game: Eat", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->endGame = false;

	//this vars are for the good eatables
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxEatables = 10;

	//these vars are for the bad eatables
	this->badSpawnTimerMax = 10.f;
	this->badSpawnTimer = this->badSpawnTimerMax;
	this->badMaxEatables = 10;
}

void Game::initMusic()
{
	if (!this->music.openFromFile("Sound/BLISSbyKENARAI.ogg"))
	{
		std::cout << "ERROR::GAME::INITMUSIC::Failed to load music...\n";
	}
}

void Game::initSound()
{
	if (!this->sBuffer.loadFromFile("Sound/Eated.wav"))
	{
		std::cout << "ERROR::GAME::INITSOUND::Failed to load sound...\n";
	}

	sound.setBuffer(sBuffer);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initSound();
	this->initMusic();
}

Game::~Game()
{
	std::cout << "Deleted...\n";
	delete this->window;
}


//functions

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvent()
{
	while (window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}


void Game::spawnEatables()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->eatables.size() < this->maxEatables)
		{
			this->eatables.push_back(Eatables(*this->window));

			this->spawnTimer = 0.f;
		}
	}
}

void Game::spawnBadEatables()
{
	if (this->badSpawnTimer < this->badSpawnTimerMax)
		this->badSpawnTimer += 1.f;
	else
	{
		if (this->badEatables.size() < this->maxEatables)
		{
			this->badEatables.push_back(Bad_Eatables(*this->window));

			this->badSpawnTimer = 0.f;
		}
	}
}

void Game::updateCollion()
{
	//check the collion
	for (size_t i = 0; i < this->eatables.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->eatables[i].getCircleShape().getGlobalBounds()))
		{
			this->eatables.erase(this->eatables.begin() + i);
			this->player.updatePoints();
			this->sound.play();
		}
	}

	//check the collion for bad eatables
	for (size_t i = 0; i < this->badEatables.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->badEatables[i].getConvexShape().getGlobalBounds()))
		{
			this->badEatables.erase(this->badEatables.begin() + i);
			this->player.updateHp();
		}
	}
}

void Game::update()
{
	this->pollEvent();

	this->spawnEatables();
	this->spawnBadEatables();

	this->player.update(this->window);
	this->updateCollion();
	this->endGameFunc();
}

void Game::render()
{
	this->window->clear();

	//render stuff
	this->player.render(this->window);

	for (auto i : this->eatables)
	{
		i.render(*this->window);
	}

	for (auto e : this->badEatables)
	{
		e.render(*this->window);
	}

	this->player.renderText(*this->window);

	this->window->display();
}

void Game::endGameFunc()
{
	if (this->player.isDead())
	{
		this->endGame = true;
	}
	else
	{
		this->endGame = false;
	}

	if (this->endGame == false)
	{
		this->window->close();
	}
}

void Game::playMusic()
{
	this->music.setLoop(true);
	this->music.play();
}



