/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:39:52 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 22:21:12 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <curses.h>
#include <unistd.h>

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
	for (int i = 0; i < 50; i++) {
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

	while (key != 'q') {
		key = this->getInput();
		if (key != -1) {
			this->getPlayerShip()->move(key);
		}
//		this->updateEntities();
		this->renderDisplay();
		sleep(0.5);
	}
}

void			Game::updateEntities( void ) {
	for (int i = 0; i < 50; i++) {
		if (this->_entities[i]) {
			this->_entities[i]->update();
		}
	}
}

void			Game::renderDisplay( void ) {
	IGameEntity	*tmp = (IGameEntity *)this->_playerShip;
	this->getMapWindow()->drawWindow(tmp);
	this->getMapWindow()->drawWindow(this->_entities, 50);
	this->getScoreWindow()->drawWindow(this);
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
