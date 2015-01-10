/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScoreWindow.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:05:39 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 22:19:26 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCOREWINDOW_HPP
# define SCOREWINDOW_HPP

# include "AWindow.hpp"
// # include <Game.hpp>
class Game;

class ScoreWindow : public AWindow {

public:
	/* Constructeur destructeur */
	ScoreWindow( void );
	ScoreWindow( ScoreWindow const & obj );
	ScoreWindow( int Lenght, int Height, int x, int y );
	~ScoreWindow( void );

	/* oprateur */
	ScoreWindow & 	operator=( ScoreWindow const & obj );

	/* fonction membre */
	void	drawWindow( void ) const;
	void	drawWindow( Game * game ) const;


};


#endif
