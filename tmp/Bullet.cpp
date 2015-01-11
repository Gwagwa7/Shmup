/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:17:35 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 08:55:54 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bullet.hpp>
#include <iostream>
#include <ASpaceShip.hpp>

Bullet::Bullet( void ) {
}

Bullet::Bullet( int x, int y, int damage ) : _X(x), _Y(y), _C('*'), _damage(damage), _type(1) {
}

Bullet::Bullet( Bullet const & src ) : _type(2) {
	*this = src;
}

Bullet::~Bullet( void ) {
}

Bullet&		Bullet::operator=( Bullet const & rhs ) {
	this->_X = rhs._X;
	this->_Y = rhs._Y;

	return *this;
}

int			Bullet::move( void ) {
	return this->move(true);
}

int			Bullet::move( bool forward ) {
	if (forward) {
		this->_Y += 1;
		if (this->_Y >= MAP_WIDTH) {
			return 0;
		}
		return 1;
	} else {
		this->_Y -= 1;
		if (this->_Y < 2) {
			return 0;
		}
		return 1;
	}
}

int			Bullet::getX( void ) const {
	return this->_X;
}

int			Bullet::getY( void ) const {
	return this->_Y;
}

int			Bullet::getDomage( void ) const {
	return this->_domage;
}

int 		Bullet::getC( void ) const {
	return this->_C;
}

int			Bullet::collide( Bullet * bullet ) {
	return 0;
}

int			Bullet::collide( ASpaceShip * ship ) {
	if (this->getY() == ship->getY() && this->getX() == ship->getX()) {
		return 3;
	}
	return 0;
}

int			Bullet::getType( void ) const {
	return this->_type;
}

int			Bullet::update( void ) {
	return this->move();
}

int			Bullet::update( bool forward ) {
	return this->move(forward);
}
