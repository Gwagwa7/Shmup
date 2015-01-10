/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:17:35 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 19:04:27 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bullet.hpp>

Bullet::Bullet( void ) {
}

Bullet::Bullet( int x, int y ) : _Y(y), _X(x), _C('*') {
}

Bullet::Bullet( Bullet const & src ) {
	*this = src;
}

Bullet::~Bullet( void ) {
}

Bullet&		Bullet::operator=( Bullet const & rhs ) {
	this->_X = rhs._X;
	this->_Y = rhs._Y;
}

void		Bullet::move( void ) {
	this->_X += 1;
}

int			Bullet::getX( void ) const {
	return this->_X;
}

int			Bullet::getY( void ) const {
	return this->_Y;
}

int			Bullet::getC( void ) const {
	return this->_C;
}
