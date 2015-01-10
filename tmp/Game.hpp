/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 12:56:56 by mcassagn          #+#    #+#             */
/*   Updated: 2015/01/10 13:47:45 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include <IGameEntity.hpp>

class Game : public IGameEntity {
	private	:
		std::string const	_playerName;
		IGameEntity			_entities[21];
		int					_score;

	public	:
		int					getInput( void );
		void				updateEntities( void );
		void				renderDisplay( void );
		void				doLoop( void );
};

#endif
