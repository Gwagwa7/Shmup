/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:56:56 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 17:05:15 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <IGameEntity.hpp>
# include <iostream>

class Game : public IGameEntity {
	private	:
		std::string const	_playerName;
		IGameEntity			*_entities[21];
		int					_score;

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
};

#endif
