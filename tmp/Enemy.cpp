/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 14:41:57 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 22:36:43 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>
#include <Bullet.hpp>
#include <iostream>

Enemy::Enemy( void ) : ASpaceShip(100,  60, 50, 10, 10, 'E') {
	this->_score = 10;
	this->initBullets();
}

Enemy::Enemy( int hp, int armor, int damage, int X, int Y ) : ASpaceShip(hp,  armor, damage, X, Y, 'E') {
	this->_score = 10;
	this->initBullets();
}

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	this->_score = 10;
	this->initBullets();
}

Enemy::~Enemy( void ) {
}

Enemy&					Enemy::operator=( Enemy const & rhs ) {
	this->_score = 10;
}

void					Enemy::attack( void ) {
	int		ind = -1;

	for (int i = 0; i < 50; i++) {
		if (this->_bullets[i] == NULL) {
			ind = i;
			break ;
		}
	}
	this->_bullets[ind] = new Bullet(this->_X + 1, this->_Y);
}

void					Enemy::update( void ) {
	if (this->_bullets) {
		for (int i = 0; i < 50; i++) {
			if (this->_bullets[i] != NULL) {
				this->_bullets[i]->update();
			}
		}
	}
}
