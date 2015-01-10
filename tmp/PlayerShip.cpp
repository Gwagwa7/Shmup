/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:41:57 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 19:06:21 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PlayerShip.hpp>
#include <Bullet.hpp>
#include <iostream>

PlayerShip::PlayerShip( void ) : ASpaceShip(100,  60, 50, 10, 10, 'P') {
	this->_live = 3;
}

PlayerShip::PlayerShip( int hp, int armor, int damage, int X, int Y ) : ASpaceShip(hp,  armor, damage, X, Y, 'P') {
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
	std::cout << "Bullet !" << std::endl;
	int		ind = -1;

	for (int i = 0; i < 50; i++) {
		if (this->_bullets[i] == NULL) {
			ind = i;
			break ;
		}
	}
//	this->_bullets[ind] = new Bullet(this->_X, this->_Y + 1);
}

int						PlayerShip::getLive( void ) const {
	return this->_live;
}
