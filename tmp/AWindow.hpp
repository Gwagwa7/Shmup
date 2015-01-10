/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:51:38 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 15:05:24 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "AWindow.hpp"

/*	Constructeur destructeur */
		AWindow::AWindow( void )
		{

			return;
		}

		AWindow::AWindow( AWindow const & obj )
		{
			*this = obj;
			return;
		}

		AWindow::~AWindow()
		{

			return;
		}

/* operteur */

		AWindow & 	AWindow::operator=( AWindow const & obj )
		{
			this->setLength( obj.getLength() );
			this->setHeight( obj.getHeight() );
			this->setWindow( obj.getWindow() );
			return *this;
		}

/* Fonction membre */

	void		AWindow::initScreen( void )
	{
		initscr();
		raw();
	}

	void		AWindow::closeScreen( void )
	{
		endwin();
	}

	void		AWindow::initNewWindow(int length , int height, int x, int y)
	{
		this->setLength(length);
		this->setHeight(height);
		this->setX(x);
		this->setY(y);

		this->setWindow(newwin(length, height , x, y));

		this->borderWindow();


	   	mvwprintw(this->getWindow() , 20 , 100 , "Y");
	   	 wrefresh(this->getWindow());

	}


	void		AWindow::drawWindow( void )
	{
		return;

	}

	void		AWindow::borderWindow( void )
	{
		int x, y, i;

		getmaxyx(this->getWindow(), y, x);
		// 4 corners
		mvwprintw(this->getWindow(), 0, 0, "+");
		mvwprintw(this->getWindow(), y - 1, 0, "+");
		mvwprintw(this->getWindow(), 0, x - 1, "+");
		mvwprintw(this->getWindow(), y - 1, x - 1, "+");
		// sides
		for (i = 1; i < (y - 1); i++) {
			mvwprintw(this->getWindow(), i, 0, "|");
			mvwprintw(this->getWindow(), i, x - 1, "|");
		}
		// top and bottom
		for (i = 1; i < (x - 1); i++) {
			mvwprintw(this->getWindow(), 0, i, "-");
			mvwprintw(this->getWindow(), y - 1, i, "-");
		}

		return;
	}



/* Get and set */

	WINDOW *	AWindow::getWindow( void ) const 	{ return this->_win; }
	int			AWindow::getLength( void ) const 	{ return this->_length; }
	int 		AWindow::getHeight( void ) const 	{ return this->_height; }
	int 		AWindow::getX( void ) const 		{ return this->_x; }
	int 		AWindow::getY( void ) const 		{ return this->_y; }

	AWindow &	AWindow::setWindow( WINDOW * win )	{ this->_win = win; return *this; }
	AWindow &	AWindow::setLength( int nbr )		{ this->_length = nbr; return *this; }
	AWindow &	AWindow::setHeight( int nbr )		{ this->_height = nbr; return *this; }
	AWindow &	AWindow::setX( int nbr )			{ this->_x = nbr; return *this; }
	AWindow &	AWindow::setY( int nbr )			{ this->_y = nbr; return *this; }




