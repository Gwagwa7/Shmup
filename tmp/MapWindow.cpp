/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapWindow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:23:07 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 22:13:30 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapWindow.hpp"
#include <iostream>

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

	void			MapWindow::drawWindow( void ) const
	{
		return;
	}

	void			MapWindow::drawWindow( IGameEntity** entities, int nb_obj ) const
	{
<<<<<<< Updated upstream
		if (entities[0]) {
			wclear(this->getWindow());
=======
		if (entities[0])
		{
			clear();
>>>>>>> Stashed changes
			this->borderWindow();
			std::string	*s;
			for (int i = 0; i < nb_obj; i ++) {
				s = new std::string(1, entities[i]->getC());
				mvwprintw(this->getWindow() , entities[i]->getX() , entities[i]->getY() , s->c_str());
<<<<<<< Updated upstream
	   			delete s;
=======
		   		delete s;
>>>>>>> Stashed changes
			}
			wrefresh(this->getWindow());
		}
		return;
	}

	void			MapWindow::drawWindow( IGameEntity* entity ) const {
<<<<<<< Updated upstream
		if (entity) {
			wclear(this->getWindow());
			this->borderWindow();
=======
		if (entity)
		{
			wclear(this->getWindow());		this->borderWindow();
>>>>>>> Stashed changes
			std::string *s = new std::string(1, entity->getC());
			mvwprintw(this->getWindow() , entity->getX() , entity->getY() , s->c_str());
			delete s;
			wrefresh(this->getWindow());
		}
<<<<<<< Updated upstream
=======
		return;
>>>>>>> Stashed changes
	}
