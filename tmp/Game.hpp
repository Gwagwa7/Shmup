/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:56:56 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/11 08:40:05 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <IGameEntity.hpp>
# include <MapWindow.hpp>
# include <PlayerShip.hpp>
# include <iostream>

class Game {
	private	:
		std::string const	_playerName;
		MapWindow const		*_map;
		IGameEntity			*_entities[50];
		PlayerShip			*_playerShip;
		int					_scorePoint;

	public	:
		Game( void );
		Game( Game const & src );
		Game( std::string const playerName );
		~Game( void );
		Game&				operator=( Game const & src );
		int					getInput( void );
		int					updateEntities( void );
		void				renderDisplay( void );
		void				doLoop( void );
		PlayerShip			*getPlayerShip( void );
		void				initMap( int width, int height, int x, int y );
		void				initScore( int width, int height, int x, int Y );
		void				destroyMap( void );
		void				destroyScore( void );
		std::string const	getPlayerName( void ) const;
		MapWindow	const	*getMapWindow( void ) const;
		void				sleepcp( int millisecond );
		IGameEntity			*checkCollide( IGameEntity * entity );
		IGameEntity			*checkCollide( ASpaceShip * ship, IGameEntity * entity );
		void				generateEnemy( void );
		int					getScore( void );
};

#endif
