/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapWindow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:23:07 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 19:01:35 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapWindow.hpp"

		MapWindow::MapWindow( void ) : AWindow( )
		{
			return;
		}

		MapWindow::MapWindow( int Lenght, int Height, int x, int y ) : AWindow( )
		{
			this->initNewWindow(Lenght, Height, x, y);
			return;
		} 

		MapWindow::MapWindow( MapWindow const & obj ) : AWindow( obj )
		{
			*this = obj;
			return ;
		}

		MapWindow::~MapWindow( void )
		{
			delwin(this->getWindow());
			return;
		}

	MapWindow &		MapWindow::operator=( MapWindow const & obj )
	{
		this->setLength( obj.getLength() );
		this->setHeight( obj.getHeight() );
		this->setWindow( obj.getWindow() );
		return *this;
	}

	void			MapWindow::drawWindow( IGameEntity** entities, int nb_obj ) const
	{
		for (int i = 0; i < nb_obj; i ++) {

			mvwprintw(this->getWindow() , entities[i]->getX() , entities[i]->getY() , "*");
	   		
		}
		wrefresh(this->getWindow());
		return;
	}
