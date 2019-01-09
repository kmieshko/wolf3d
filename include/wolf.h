/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:00:46 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/17 17:00:48 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <../frm/SDL2_mixer.framework/Versions/A/Headers/SDL_mixer.h>
# include <OpenCL/OpenCL.h>

# include <stdio.h> /////////////////////////////

# define WIN_W		640
# define WIN_H		480
# define TS			262144
# define TEXT_W		512
# define TEXT_H		512
# define WEAPON_H	347
# define WS			120409
# define NB_TEXT	6
# define WHITE		0xffffff
# define BLACK		0x0

typedef struct		s_window
{
	SDL_Event		e;
	SDL_Surface		*surface;
	SDL_Window		*window;
	Mix_Music		*music;
	int				quit;
}					t_window;

typedef	struct		s_constit
{
	int				x;
	int				y;
}					t_constit;

typedef	struct		s_double_constit
{
	double			x;
	double			y;
}					t_double_constit;

typedef struct		s_map
{
	int				**data;
	int				col;
	int				rows;
	int				x;
	int				y;
}					t_map;

typedef struct		s_texture
{
	int	a[TS];
	int	b[TS];
	int	c[TS];
	int	d[TS];
	int	e[TS];
	int	f[TS];
	int	w[WS];
}					t_texture;

typedef struct		s_wolf
{
	t_map				map;
	t_double_constit	start;
	t_constit			int_start;
	t_constit			dir_vec;
	t_double_constit	plane;
	t_double_constit	ray_dir;
	t_double_constit	dir;
	t_double_constit	cam;
	t_double_constit	side_dist; //length of ray from current position to next x or y-side
	t_double_constit	delta_dist; //length of ray from one x or y-side to next x or y-side
	double				move_speed;
	double				rot_speed;
	t_constit			step;
	int					intersect;
	int					side;
	t_texture			textures;
	int					switcher;
	double			dist_to_wall;
	double			inten;
	int				wall_height;
	int				draw_start;
	int				draw_end;
	int				nb_text;
	double			wall_hit;
	t_constit		text;
	int				color;
	int				w_color;
	int				weapon;
	double			cur_dist;
	t_double_constit	floor;
}					t_wolf;

void		error(char *str);
void		parse_map(char *filename, t_map *map, int j, int i);
void		ft_pixel_put(SDL_Surface *surface, int x, int y, int color);
void		find_person_position(t_wolf *wolf);
double		ft_clamp_with_param(double value, double min, double max);
int			get_color(int color, double intensity);
void		get_textures(t_wolf *wolf);
void		manage(t_window *win, t_wolf *wolf);
void		calc_ray_pos_and_dir(t_wolf *wolf, int x);
void		calc_step_and_init_side_dist(t_wolf *wolf);
void		dda_algorithm(t_wolf *wolf);
void		calc_wall_hit(t_wolf *wolf);
void		calc_x_coord_on_texture(t_wolf *wolf);
void	init_structure_window(t_window *win, char *name);
void	init_structure_wolf(t_wolf *wolf);

void	choose_wall_color(t_wolf *wolf);
void	fill_buffer_wall_colors(t_wolf *w, int buffer[WIN_H][WIN_W], int x);
void	get_music(Mix_Music *music);
void	draw_buffer(t_window *win, int buffer[WIN_H][WIN_W]);
void	draw_weapon(t_wolf *wolf, int buffer[WIN_H][WIN_W], int x);
void		get_floor_coord(t_wolf *wolf);
void	fill_buf_ceiling_floor(t_wolf *wolf, int buffer[WIN_H][WIN_W], int x);

#endif