/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerShip.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:36:05 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 08:47:21 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PLAYERSHIP_HPP
# define PLAYERSHIP_HPP

# include <ASpaceShip.hpp>

class PlayerShip : public ASpaceShip {
	private	:
		int			_live;

	public	:
		PlayerShip( void );
		PlayerShip( PlayerShip const & src );
		PlayerShip( int hp, int armor, int damage, int X, int Y );
		virtual ~PlayerShip( void );
		PlayerShip&		operator=( PlayerShip const & rhs );
		void		attack( void );
		int			getLive( void ) const;
		int			update( void );
};

#endif
