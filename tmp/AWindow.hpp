/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWindow.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:51:38 by apantiez          #+#    #+#             */
/*   Updated: 2015/01/10 16:03:39 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWINDOW_HPP
# define AWiNDOW_HPP

class AWindow : {

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

	void			initScreen( void );

	void			closeScreen( void );

	void			initNewWindow(int length , int height, int x, int y);

	void			borderWindow( void );

	virtual void	AWindow::drawWindow( void ) = 0;


	/* get and set */
	WINDOW *	AWindow::getWindow( void ) const;
	int			AWindow::getLength( void ) const;
	int 		AWindow::getHeight( void ) const;	
	int 		AWindow::getX( void ) const;	
	int 		AWindow::getY( void ) const;		

	AWindow &	AWindow::setWindow( WINDOW * win );
	AWindow &	AWindow::setLength( int nbr );
	AWindow &	AWindow::setHeight( int nbr );		
	AWindow &	AWindow::setX( int nbr );		
	AWindow &	AWindow::setY( int nbr );			

};

#endif

