/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapWindow.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:22:44 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 18:53:18 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPWINDOW_HPP
# define MAPWINDOW_HPP

# include "AWindow.hpp"

class MapWindow : public AWindow {


public:
	/* Constructeur destructeur */
	MapWindow( void );
	MapWindow( MapWindow const & obj );
	MapWindow( int Lenght, int Height, int x, int y );
	~MapWindow();

	/* oprateur */
	MapWindow & 	operator=( MapWindow const & obj );

	/* fonction membre */
	void	drawWindow( IGameEntity** entities ) const;
};


#endif
