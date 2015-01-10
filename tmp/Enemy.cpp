/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:41:57 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 16:00:24 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>
#include <iostream>

Enemy::Enemy( void ) : ASpaceShip(100,  60, 50, 10, 10) {
	this->_score = 10;
}

Enemy::Enemy( int hp, int armor, int damage, int X, int Y ) : ASpaceShip(hp,  armor, damage, X, Y) {
	this->_score = 10;
}

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	this->_score = 10;
}

Enemy::~Enemy( void ) {
}

Enemy&					Enemy::operator=( Enemy const & rhs ) {
	this->_score = 10;
}

void					Enemy::attack( void ) {
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
