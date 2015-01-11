/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:05:08 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 01:36:16 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP

# define MAP_WIDTH 		200
# define SCORE_WIDTH 	200
# define HEIGHT			50
# define NB_BULLET		50
# define NB_ENTITY		50

class IGameEntity {
	public	:
		virtual	int				getX( void ) const = 0;
		virtual	int				getY( void ) const = 0;
		virtual int const		getC( void ) const = 0;
		virtual int				update( void ) = 0;
};

#endif
