/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScoreWindow.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:11:18 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 22:01:36 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScoreWindow.hpp>


	ScoreWindow::ScoreWindow( void ) : AWindow( )
	{
		return;
	}

	ScoreWindow::ScoreWindow( int Lenght, int Height, int x, int y ) : AWindow( )
	{
		this->initNewWindow(Lenght, Height, x, y);
		return;
	} 

	ScoreWindow::ScoreWindow( ScoreWindow const & obj ) : AWindow( obj )
	{
		*this = obj;
		return ;
	}

	ScoreWindow::~ScoreWindow( void )
	{
		delwin(this->getWindow());
		return;
	}

	ScoreWindow &		ScoreWindow::operator=( ScoreWindow const & obj )
	{
		this->setLength( obj.getLength() );
		this->setHeight( obj.getHeight() );
		this->setWindow( obj.getWindow() );
		return *this;
	}

	void			ScoreWindow::drawWindow( void ) const
	{
		return;
	}


	void			ScoreWindow::drawWindow( Game & game ) const
	{
		clear();
		this->borderWindow();
		mvwprintw(this->getWindow() , this->getX() + 2 , this->getY() + 20, "Life is here");		
		wrefresh(this->getWindow());
		return;
	}
	