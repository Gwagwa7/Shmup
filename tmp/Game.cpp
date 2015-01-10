/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:39:52 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 16:53:38 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>

Game::Game( void ) : _playerName("playerOne"), _score(0) {
}

Game::Game( Game const & src ) {
	*this = src;
}

Game::Game( std::string const playerName ) :
	_playerName(playerName),
	_score(0)
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

int				Game::getInput( void ) {

}
