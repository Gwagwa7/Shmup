/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:48:18 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 16:02:58 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ASpaceShip.hpp>

ASpaceShip::ASpaceShip( void ) {
}

ASpaceShip::ASpaceShip( ASpaceShip const & src ) {
	*this = src;
}

ASpaceShip::ASpaceShip( int hp, int armor, int damage, int X, int Y ) :
	_HP(hp), _armor(armor), _maxHP(hp), _X(X), _Y(Y), _alive(true), _damage(damage)
{
}

ASpaceShip::~ASpaceShip( void ) {
}

ASpaceShip&		ASpaceShip::operator=( ASpaceShip const & rhs ) {
	this->_HP = rhs._HP;
	this->_maxHP = rhs._maxHP;
	this->_armor = rhs._armor;
	this->_damage = rhs._damage;
	this->_X = rhs._X;
	this->_Y = rhs._Y;
	this->_alive = rhs._alive;
	return *this;
}

int				ASpaceShip::getHP( void ) const {
	return this->_HP;
}

void			ASpaceShip::takeDamage( int amount ) {
	amount -= this->_armor;
	amount = (amount < 0) ? 0 : amount;
	this->_HP -= amount;
	this->_alive = (this->_HP < 0) ? false : true;
}

bool			ASpaceShip::isAlive( void ) const {
	return this->_alive;
}

void			ASpaceShip::move( int x, int y ) {
	this->_X += x;
	this->_Y += y;
	this->_X = (this->_X < 0) ? 0 : this->_X;
	this->_Y = (this->_Y < 0) ? 0 : this->_Y;
}

int				ASpaceShip::getY( void ) const {
	return this->_Y;
}

int				ASpaceShip::getX( void ) const {
	return this->_X;
}
