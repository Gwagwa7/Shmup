#include <PlayerShip.hpp>
#include <Bullet.hpp>
#include <Game.hpp>
#include <Enemy.hpp>

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

#include <MapWindow.hpp>

Game		*init_game(std::string const name) {
	Game *game = new Game(name);
	MapWindow::initScreen();
	return game;
}

int main(int ac, char **av)
{
	Game *game;
	IGameEntity	*objects[50];
	for (int i = 0; i < 50; i++) {
		objects[i] = (IGameEntity*) new Enemy();
	}

	if (ac == 2) {
		game = init_game(av[1]);

		game->initMap(200, 50, 0, 0);
		game->initScore(30, 50, 0, 201);
		game->doLoop();
		std::cout << "Je suis le joueur " << game->getPlayerName() << std::endl;
		std::cout << "Il me reste " << game->getPlayerShip().getLive() << " vie." << std::endl;
		std::cout << "Mon vaisseau a " << game->getPlayerShip().getHP() << " points de vie." << std::endl;
		std::cout << "Il est en X: " << game->getPlayerShip().getX() << " Y: " << game->getPlayerShip().getY() << std::endl;
		MapWindow::closeScreen();
	} else {
		std::cout << "Usage: ./ft_retro <playerName>" << std::endl;
	}
}
