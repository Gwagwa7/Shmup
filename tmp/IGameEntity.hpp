/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:05:08 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 21:55:16 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP

class IGameEntity {
	public	:
		virtual	int				getX( void ) const = 0;
		virtual	int				getY( void ) const = 0;
		virtual int const		getC( void ) const = 0;
		virtual void			update( void ) = 0;
};

#endif
