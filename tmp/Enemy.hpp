/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:36:05 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 05:33:52 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ENEMY_HPP
# define ENEMY_HPP

# include <ASpaceShip.hpp>

class Enemy : public ASpaceShip {
	private	:
		int			_score;

	public	:
		Enemy( void );
		Enemy( Enemy const & src );
		Enemy( int hp, int armor, int damage, int X, int Y );
		~Enemy( void );
		Enemy&		operator=( Enemy const & rhs );
		void		attack( void );
		int			update( void );
		int			getScore( void );
};

#endif
