// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"


int main()
{
	//game loop and random number
	srand(static_cast<unsigned>(time(nullptr)));

	//creates a game object
	Game game;

	game.playMusic(); //Plays the music and loops it.

	while (game.running())
	{
		game.update();
		
		game.render();
	}

	return 0;
}

