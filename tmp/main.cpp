#include <PlayerShip.hpp>
#include <Enemy.hpp>
#include <AWindow.hpp>
#include <iostream>
#include <unistd.h>

int main(void)
{
/*	ASpaceShip*	objects[50];

	for ( int i = 1; i < 51; i++ ) {
		objects[i - 1] = new Enemy(20 * i, 3 * i, 10 * i, 3 * i, 3 * i);
	}
	for ( int i = 0; i < 50; i++ ) {
		std::cout << "X: " << objects[i]->getX() << " Y: " << objects[i]->getY() << std::endl;
	}*/

	AWindow		*window = new AWindow();

	window->initScreen();
	window->initNewWindow(50, 200, 0, 0);
	sleep(10);
	window->closeScreen();
}
