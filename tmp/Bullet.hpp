/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:43:09 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 15:56:34 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <IGameEntity.hpp>

class Bullet : public IGameEntity {
	private	:
		int		_X;
		int		_Y;

	public	:
		void	move( int x, int y );
};

#endif
