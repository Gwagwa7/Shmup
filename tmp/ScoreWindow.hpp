/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScoreWindow.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:05:39 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 19:16:40 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCOREWINDOW_HPP
# define SCOREWINDOW_HPP

# include "AWindow.hpp"

class ScoreWindow : public AWindow {

public:
	/* Constructeur destructeur */
	ScoreWindow( void );
	ScoreWindow( MapWindow const & obj );
	ScoreWindow( int Lenght, int Height, int x, int y );
	~ScoreWindow( void );

	/* oprateur */
	MapWindow & 	operator=( MapWindow const & obj );

	/* fonction membre */
	void	drawWindow( IGameEntity** entities, int nb_obj = 0 ) const;


};


#endif