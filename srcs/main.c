/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:51:39 by kmieshko          #+#    #+#             */
/*   Updated: 2019/01/09 19:51:40 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int argc, char **argv)
{
	t_window	win;
	t_wolf		wolf;

	if (argc < 2)
		error("No arguments found");
	else if (argc > 2)
		error("Use only one argument");
	parse_map(argv[1], &(wolf.map), 0, 0);
	find_person_position(&wolf);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return (0);
	init_structure_window(&win, argv[1]);
	init_structure_wolf(&wolf);
	get_textures(&wolf);
	get_music(win.music);
	main_loop(&win, &wolf);
	free_all(&win);
	return (0);
}
