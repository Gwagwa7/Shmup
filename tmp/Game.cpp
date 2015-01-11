/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:39:52 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 06:26:03 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <Enemy.hpp>
#include <curses.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

Game::Game( void ) : _playerName("playerOne"), _score(0), _playerShip(new PlayerShip()) {
}

Game::Game( Game const & src ) {
	*this = src;
}

Game::Game( std::string const playerName ) :
	_playerName(playerName),
	_score(0),
	_playerShip(new PlayerShip())
{
	for (int i = 0; i < NB_ENEMY; i++) {
		this->_entities[i] = NULL;
	}
}

Game::~Game( void ) {
}

Game&			Game::operator=( Game const & rhs ) {
	this->_score = rhs._score;
	for (int i = 0; i < NB_ENTITY; i++) {
		this->_entities[i] = rhs._entities[i];
	}
	return *this;
}

PlayerShip*		Game::getPlayerShip( void ) {
	return this->_playerShip;
}

std::string const	Game::getPlayerName( void ) const {
	return this->_playerName;
}

void			Game::generateEnemy( void ) {
	for (int i = 0; i < NB_ENEMY; i++) {
		if (rand() % 7 != 1) {
			if (!this->_entities[i]) {
				this->_entities[i] = new Enemy(100, 10, 10, (i + 1) * 3, MAP_WIDTH - 2);
			}
		}
	}
}

void			Game::doLoop( void ) {
	int			key = 42;
	clock_t		time_start;
	float		tmp;
	clock_t 	diff;

	srand(time(NULL));
	while (key != 'q') {
		time_start = clock();
		this->generateEnemy();
		key = this->getInput();
		if (key != -1) {
			if (key == ' ') {
				this->getPlayerShip()->attack();
			} else {
				this->getPlayerShip()->move(key);
			}
		}
		this->updateEntities();
		if (!this->getPlayerShip()) {
			return ;
		}
		this->renderDisplay();
		diff = clock() - time_start;
		tmp = ((float)diff)/CLOCKS_PER_SEC;
		this->sleepcp( 50 - tmp);
	}
}

void			Game::sleepcp( int millisecond )
{
	if (millisecond > 0)
	{
		clock_t time_end;
		time_end = clock() + millisecond * CLOCKS_PER_SEC/1000;
		while (clock() < time_end)
		{
		}
	}
}

IGameEntity			*Game::checkCollide( ASpaceShip * ship, IGameEntity * entity ) {
	Enemy*			tmp;
	tmp = (Enemy *)entity;
	int ret = tmp->collide(ship);
	switch (ret) {
		case 2	:
			delete ship;
			ship = NULL;
			return entity;
		case 3	:
			delete ship;
			delete entity;
			ship = NULL;
			return NULL;
	}
	ret = ship->collide(tmp);
	switch (ret) {
		case 2	:
			delete entity;
			entity = NULL;
			return NULL;
		case 3	:
			delete ship;
			delete entity;
			ship = NULL;
			return NULL;
	}
	return entity;
}

IGameEntity			*Game::checkCollide( IGameEntity * entity) {
	IGameEntity**		entities = this->_entities;
	int				ret = -1;
	for (int i = 0; i < NB_ENTITY; i++) {
		if (entities[i]) {
			switch (entities[i]->getType()) {
				case 0	:
					ret = entity->collide((Enemy *)entities[i]);
					break;
				case 1	:
					ret = entity->collide((Bullet *)entities[i]);
					break;
				case 2	:
					ret = entity->collide((PlayerShip *)entities[i]);
					break;
			}
			if (entity != entities[i]) {
				switch (ret) {
					case 1	:
						delete entity;
						return NULL;
					case 2	:
						delete entities[i];
						entities[i] = NULL;
						return entity;
					case 3	:
						delete entities[i];
						delete entity;
						entities[i] = NULL;
						return NULL;
				}
			}
		}
	}
	return entity;
}

void			Game::updateEntities( void ) {
	int			score;
	Enemy*		enemy;
	this->getPlayerShip()->update();
	this->_playerShip = (PlayerShip *) this->checkCollide(this->getPlayerShip());
	if (this->_playerShip) {
		for (int i = 0; i < NB_ENTITY; i++) {
			score = 0;
			if (this->_entities[i]) {
				enemy = (Enemy *) this->_entities[i];
				if (this->_entities[i]->update() == -1) {
					delete this->_entities[i];
					this->_entities[i] = NULL;
				} else {
					score = enemy->getScore();
					this->_entities[i] = this->checkCollide(this->_playerShip, this->_entities[i]);
					if (!this->_playerShip) {
						break;
					}
					if (this->_entities[i]) {
						this->_entities[i] = this->checkCollide(this->_entities[i]);
					} else {
						this->_score += score;
					}
				}
			}
		}
	}
}

void			Game::renderDisplay( void ) {
	IGameEntity	*spaceShip = (IGameEntity *)this->_playerShip;
	Bullet		**tmp = this->_playerShip->getBullet();
	IGameEntity **bullets = (IGameEntity **)tmp;

	this->getMapWindow()->clear();
	this->getScoreWindow()->clear();
	this->getMapWindow()->drawWindow(spaceShip);
	this->getMapWindow()->drawWindow(this->_entities, NB_ENTITY);
	this->getMapWindow()->drawWindow(bullets, NB_BULLET);
	this->getScoreWindow()->drawWindow(this);
	this->getMapWindow()->refresh();
	this->getScoreWindow()->refresh();
}

int				Game::getInput( void ) {
	int			key = getch();
	return key;
}

void			Game::initMap( int width, int height, int x, int y ) {
	this->_map = new MapWindow(width, height, x, y);
}

void			Game::initScore( int width, int height, int x, int y ) {
	this->_score = new ScoreWindow(width, height, x, y);
}

MapWindow const *		Game::getMapWindow( void ) const {
	return this->_map;
}

ScoreWindow const *		Game::getScoreWindow( void ) const {
	return this->_score;
}

int						Game::getScore( void ) {
	return this->_scorePoint;
}
