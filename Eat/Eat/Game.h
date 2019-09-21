#pragma once

#include <SFML/Audio.hpp>
#include <vector>
#include "Player.h"
#include "Eatables.h"
#include "Bad_Eatables.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;
	sf::SoundBuffer sBuffer;
	sf::Sound sound;
	sf::Music music;

	bool endGame;

	Player player;

	//Ememy stuff
	std::vector <Eatables> eatables;
	float spawnTimerMax;
	float spawnTimer;
	unsigned int maxEatables;
	std::vector <Bad_Eatables> badEatables;
	float badSpawnTimerMax;
	float badSpawnTimer;
	unsigned int badMaxEatables;


	//private functions
	void initWindow();
	void initVariables();
	void initMusic();
	void initSound();


public:
	Game();
	~Game();

	//functions
	const bool running() const;
	void pollEvent();

	void spawnEatables();
	void spawnBadEatables();
	void updateCollion();
	void playMusic();
	void update();

	void render();

	void endGameFunc();
};

