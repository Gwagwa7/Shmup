/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:56:56 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 22:12:59 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <IGameEntity.hpp>
# include <MapWindow.hpp>
# include <ScoreWindow.hpp>
# include <PlayerShip.hpp>
# include <iostream>

class Game {
	private	:
		std::string const	_playerName;
		MapWindow const		*_map;
		ScoreWindow const	*_score;
		IGameEntity			*_entities[21];
		PlayerShip			*_playerShip;
		int					_scorePoint;

	public	:
		Game( void );
		Game( Game const & src );
		Game( std::string const playerName );
		~Game( void );
		Game&				operator=( Game const & src );
		int					getInput( void );
		void				updateEntities( void );
		void				renderDisplay( void );
		void				doLoop( void );
		PlayerShip			*getPlayerShip( void );
		void				initMap( int width, int height, int x, int y );
		void				initScore( int width, int height, int x, int Y );
		void				destroyMap( void );
		void				destroyScore( void );
		std::string const	getPlayerName( void ) const;
		MapWindow	const	*getMapWindow( void ) const;
		ScoreWindow	const	*getScoreWindow( void ) const;
};

#endif
