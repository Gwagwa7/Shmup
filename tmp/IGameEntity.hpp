/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGameEntity.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 11:05:08 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 17:05:17 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_HPP
# define IGAMEENTITY_HPP

class IGameEntity {
	public	:
		virtual	int		getX() const = 0;
		virtual	int		getY() const = 0;
};

#endif
