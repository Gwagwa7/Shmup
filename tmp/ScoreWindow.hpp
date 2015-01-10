/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScoreWindow.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:05:39 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 19:24:09 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCOREWINDOW_HPP
# define SCOREWINDOW_HPP

# include "AWindow.hpp"

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
	void	drawWindow( IGameEntity** entities, int nb_obj ) const;


};


#endif
