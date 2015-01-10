/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:51:38 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 19:21:59 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWINDOW_HPP
# define AWINDOW_HPP

# include <IGameEntity.hpp>
# include <curses.h>

class AWindow {

private:
	WINDOW *	_win;
	int			_length;
	int 		_height; 
	int 		_x; 
	int 		_y;

public:
	/*	Constructeur destructeur */
		AWindow( void );
		AWindow( AWindow const & obj );
		~AWindow();

	/* operteur */

	AWindow & 	operator=( AWindow const & obj );

	/* Fonction membre */

	static void		initScreen( void );

	static void		closeScreen( void );

	void			initNewWindow(int length , int height, int x, int y);

	void			borderWindow( void );

	virtual void	drawWindow( IGameEntity** entities, int nb_obj ) const = 0;


	/* get and set */
	WINDOW *	getWindow( void ) const;
	int			getLength( void ) const;
	int 		getHeight( void ) const;	
	int 		getX( void ) const;	
	int 		getY( void ) const;		

	AWindow &	setWindow( WINDOW * win );
	AWindow &	setLength( int nbr );
	AWindow &	setHeight( int nbr );		
	AWindow &	setX( int nbr );		
	AWindow &	setY( int nbr );			

};

#endif

