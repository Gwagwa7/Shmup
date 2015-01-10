/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:43:09 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 19:10:18 by mcassagn         ###   ########.fr       */
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

	public	:
		Bullet( void );
		Bullet( Bullet const & src );
		Bullet( int x, int y );
		~Bullet( void );
		Bullet&		operator=( Bullet const & rhs );
		void		move( void );
		int			getX( void ) const;
		int			getY( void ) const;
		int	const	getC( void ) const;
};

#endif
