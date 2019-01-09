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

void	clear_buffer(int buffer[WIN_H][WIN_W])
{
	int i;
	int j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			buffer[i][j] = 0;
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_window	win;
	t_wolf		wolf;
	int			buffer[WIN_H][WIN_W];
	int			x;

	if (argc < 2)
		error("No arguments found");
	else if (argc > 2)
		error("Use only one argument");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return (0);
	parse_map(argv[1], &(wolf.map), 0, 0);
	find_person_position(&wolf);
	init_structure_window(&win, argv[1]);
	init_structure_wolf(&wolf);
	get_textures(&wolf);
	get_music(win.music);

	while (!win.quit)
	{
		while (SDL_PollEvent(&win.e) != 0)
		{
			if (win.e.type == SDL_QUIT)
				win.quit = 1;
			if (win.e.type == SDL_KEYDOWN)
			{
				if (win.e.key.keysym.sym == SDLK_ESCAPE)
				{
					win.quit = 1;
					break ;
				}
				if (win.e.key.keysym.sym == SDLK_s)
					wolf.switcher *= -1;
				if (win.e.key.keysym.sym == SDLK_w)
					wolf.weapon *= -1;
				if (win.e.key.keysym.sym == SDLK_l)
					system("leaks wolf3d");
			}
		}
		x = 0;
		while (x < WIN_W)
		{
			calc_ray_pos_and_dir(&wolf, x);
			wolf.map.x = (int)wolf.start.x;
			wolf.map.y = (int)wolf.start.y;
			wolf.delta_dist.x = fabs(1 / wolf.ray_dir.x);
			wolf.delta_dist.y = fabs(1 / wolf.ray_dir.y);
			calc_step_and_init_side_dist(&wolf);
			dda_algorithm(&wolf);
			if (wolf.side == 0 || wolf.side == 2)
				wolf.dist_to_wall = (wolf.map.x - wolf.start.x + (1 - wolf.step.x) / 2) / wolf.ray_dir.x;
			else
				wolf.dist_to_wall = (wolf.map.y - wolf.start.y + (1 - wolf.step.y) / 2) / wolf.ray_dir.y;
			wolf.inten = wolf.weapon > 0 ? ft_clamp_with_param(1 - (wolf.dist_to_wall / sqrt(pow(wolf.map.rows, 2) + pow(wolf.map.col, 2))), 0.1, 1) : 1;
			wolf.wall_height = (int)(WIN_H / wolf.dist_to_wall);
			if (wolf.wall_height == 0)
				wolf.wall_height = 1;
			wolf.draw_start = -wolf.wall_height / 2 + WIN_H / 2;
			if (wolf.draw_start < 0)
				wolf.draw_start = 0;
			wolf.draw_end = wolf.wall_height / 2 + WIN_H / 2;
			if (wolf.draw_end >= WIN_H)
				wolf.draw_end = WIN_H;
			wolf.nb_text = wolf.map.data[wolf.map.x][wolf.map.y];
			calc_wall_hit(&wolf);
			calc_x_coord_on_texture(&wolf);
			fill_buffer_wall_colors(&wolf, buffer, x);
			get_floor_coord(&wolf);
			fill_buf_ceiling_floor(&wolf, buffer, x);
			draw_weapon(&wolf, buffer, x);
			x++;
		}
		draw_buffer(&win, buffer);
		clear_buffer(buffer);
		manage(&win, &wolf);
		SDL_UpdateWindowSurface(win.window);
	}
	Mix_FreeMusic(win.music);
	Mix_CloseAudio();
	SDL_FreeSurface(win.surface);
	SDL_DestroyWindow(win.window);
	win.surface = NULL;
	win.window = NULL;
	SDL_Quit();
	return (0);
}
