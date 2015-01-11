/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapWindow.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:22:44 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/11 05:13:38 by apantiez         ###   ########.fr       */
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
	void	drawWindow( void ) const;
	void	drawWindow( IGameEntity** entities, int nb_obj ) const;
	void	drawWindow( IGameEntity* entity ) const;
	void	font(  int & x, int & y ) const;

private:
	int 	_fontX;
	int 	_fontY;
};


#endif
