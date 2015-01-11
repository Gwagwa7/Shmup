/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScoreWindow.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:11:18 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/11 04:52:59 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScoreWindow.hpp>
#include <Game.hpp>


	ScoreWindow::ScoreWindow( void ) : AWindow( )
	{
		this->_str = "";
		return;
	}

	ScoreWindow::ScoreWindow( int Lenght, int Height, int x, int y ) : AWindow( )
	{
		this->initNewWindow(Lenght, Height, x, y);
		this->_str = "";
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

	void	ScoreWindow::print( std::string str)
	{
		this->_str = str;
	}


	void			ScoreWindow::drawWindow( Game * game ) const
	{
		this->borderWindow();

		
		mvwprintw(this->getWindow() , 1 , 1, "Player : ", game->getPlayerName().c_str());
		mvwprintw(this->getWindow() , 5 , 1, "Score : ", game->getScore());
//		mvwprintw(this->getWindow() , 10 , 1, "Life :");
		//mvwprintw(this->getWindow() , 15 , 1, "Nb Life :");
		

		mvwprintw(this->getWindow(), 0, 0, this->_str.c_str());
		return;
	}
	