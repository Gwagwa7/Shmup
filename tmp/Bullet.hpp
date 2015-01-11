/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:43:09 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 08:58:40 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <IGameEntity.hpp>

class Bullet : public IGameEntity {
	private	:
		int		_X;
		int		_Y;
		int		_C;
		int		_damage;
		int		_type;

	public	:
		Bullet( void );
		Bullet( Bullet const & src );
		Bullet( int x, int y, int damage );
		~Bullet( void );
		Bullet&		operator=( Bullet const & rhs );
		int			move( void );
		int			move( bool forward );
		int			getX( void ) const;
		int			getY( void ) const;
		int 		getC( void ) const;
		int 		getDamage( void ) const;
		int			getType( void ) const;
		int			update( void );
		int			update( bool forward );
		int			collide( ASpaceShip * ship );
		int			collide( Bullet * bullet );
};

#endif
