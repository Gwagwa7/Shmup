/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:39:52 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 01:37:56 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <curses.h>
#include <unistd.h>
#include <ctime>

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

void			Game::doLoop( void ) {
	int			key = 42;
	clock_t		time_start;
	float		tmp;
	clock_t 	diff;

	while (key != 'q') {
		time_start = clock();
		key = this->getInput();
		if (key != -1) {
			if (key == ' ') {
				this->getPlayerShip()->attack();
			}
			this->getPlayerShip()->move(key);
		}
		this->updateEntities();
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

//void			Game::checkCollide( IGameEntity * entity ) {
	
//}

void			Game::updateEntities( void ) {
	this->getPlayerShip()->update();
	for (int i = 0; i < NB_ENTITY; i++) {
		if (this->_entities[i]) {
			this->_entities[i]->update();
			//this->checkCollide(this->_entities[i]);
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
//	this->getMapWindow()->drawWindow(this->_entities, NB_ENTITY);
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
