#include <PlayerShip.hpp>
#include <Bullet.hpp>
#include <Enemy.hpp>

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

#include "MapWindow.hpp"

int		test(IGameEntity** entities) {
	for (int i = 0; i < 50; i ++) {
		std::cout << entities[i]->getX() << std::endl;
	}
}

int main(void)
{
/*	ASpaceShip*	object = new PlayerShip(20, 3, 10, 3, 3);
	srand(time(NULL));
	int randd = 0;

	for ( int i = 0; i < 50; i++ ) {
		randd = rand() % 4;
		if (randd % 4 == 0) {
			object->move(1, 0);
		} else if (randd % 4 == 1) {
			object->move(-1, 0);
		} else if (randd % 4 == 2) {
			object->move(0, 1);
		} else if (randd % 4 == 3) {
			object->move(0, -1);
		}
		std::cout << "Object X: " << object->getX() << " Y: " << object->getY() << std::endl;
	}*/

	Bullet *objects[50];
	IGameEntity **tmp;
	tmp = (IGameEntity**)objects;
	for (int i = 0; i < 50; i++) {
		objects[i] = new Bullet( 10, i + 5);
	}
//	test(tmp);

	MapWindow *Window = new MapWindow(200, 50, 3, 5);

	Window->drawWindow(tmp);

	sleep(10);

	Window->closeScreen();

	delete Window;


}


