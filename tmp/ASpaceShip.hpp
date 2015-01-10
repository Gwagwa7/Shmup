/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:52:04 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 15:25:01 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPACE_SHIP_HPP
# define ASPACE_SHIP_HPP

# include <IGameEntity.hpp>

class ASpaceShip : public IGameEntity {
	protected	:
		int			_HP;
		int			_maxHP;
		int			_armor;
		int			_damage;
		int			_X;
		int			_Y;
		bool		_alive;
		IGameEntity	*_bullets[50];

	public		:
		ASpaceShip( void );
		ASpaceShip( ASpaceShip const & src );
		ASpaceShip( int hp, int armor, int damage, int X, int Y );
		~ASpaceShip( void );
		ASpaceShip&		operator=( ASpaceShip const & rhs );
		void			move( int x, int y);
		virtual void	attack( void ) = 0;
		void			takeDamage( int amount );
		bool			isAlive( void ) const;
		int				getHP( void ) const;
};

#endif
