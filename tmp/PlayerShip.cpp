/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:41:57 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 08:08:40 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PlayerShip.hpp>
#include <Bullet.hpp>
#include <iostream>
#include <ctime>

PlayerShip::PlayerShip( void ) : ASpaceShip(100,  60, 50, 3, 3, 'P', 2) {
	this->_live = 3;
}

PlayerShip::PlayerShip( int hp, int armor, int damage, int X, int Y ) : ASpaceShip(hp,  armor, damage, X, Y, 'P', 2) {
	this->_live = 3;
}

PlayerShip::PlayerShip( PlayerShip const & src ) {
	*this = src;
}

PlayerShip&					PlayerShip::operator=( PlayerShip const & rhs ) {
	this->_live = rhs._live;
}

PlayerShip::~PlayerShip( void ) {
}

void					PlayerShip::attack( void ) {
	int		ind = -1;

	for (int i = 0; i < NB_BULLET; i++) {
		if (this->_bullets[i] == NULL) {
			ind = i;
			break ;
		}
	}
	if (ind != -1) {
		this->_bullets[ind] = new Bullet(this->_X, this->_Y + 1, this->_damage);
	}
}

int						PlayerShip::getLive( void ) const {
	return this->_live;
}

int						PlayerShip::update( void ) {
	if (this->_bullets) {
		for (int i = 0; i < NB_BULLET; i++) {
			if (this->_bullets[i] != NULL) {
				if (this->_bullets[i]->update() == 0) {
					delete this->_bullets[i];
					this->_bullets[i] = NULL;
				}
			}
		}
	}
}
