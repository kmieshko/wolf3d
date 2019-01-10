/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:08:10 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/20 17:08:11 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	down(t_wolf *wolf)
{
	if (wolf->dir.x > 0)
		if (!wolf->map.data[(int)(wolf->start.x -
			wolf->dir.x * wolf->move_speed - 0.1)][(int)(wolf->start.y)])
			wolf->start.x -= (wolf->dir.x * wolf->move_speed);
	if (wolf->dir.x <= 0)
		if (!wolf->map.data[(int)(wolf->start.x -
			wolf->dir.x * wolf->move_speed + 0.1)][(int)(wolf->start.y)])
			wolf->start.x -= (wolf->dir.x * wolf->move_speed);
	if (wolf->dir.y > 0)
		if (!wolf->map.data[(int)(wolf->start.x)][(int)(wolf->start.y -
			wolf->dir.y * wolf->move_speed - 0.1)])
			wolf->start.y -= wolf->dir.y * wolf->move_speed;
	if (wolf->dir.y <= 0)
		if (!wolf->map.data[(int)(wolf->start.x)][(int)(wolf->start.y -
			wolf->dir.y * wolf->move_speed + 0.1)])
			wolf->start.y -= wolf->dir.y * wolf->move_speed;
}

static void	up_down(t_wolf *wolf, int direction)
{
	if (direction > 0)
	{
		if (wolf->dir.x > 0)
			if (!wolf->map.data[(int)(wolf->start.x +
				wolf->dir.x * wolf->move_speed + 0.1)][(int)(wolf->start.y)])
				wolf->start.x += (wolf->dir.x * wolf->move_speed);
		if (wolf->dir.x <= 0)
			if (!wolf->map.data[(int)(wolf->start.x +
				wolf->dir.x * wolf->move_speed - 0.1)][(int)(wolf->start.y)])
				wolf->start.x += (wolf->dir.x * wolf->move_speed);
		if (wolf->dir.y > 0)
			if (!wolf->map.data[(int)(wolf->start.x)][(int)(wolf->start.y +
				wolf->dir.y * wolf->move_speed + 0.1)])
				wolf->start.y += wolf->dir.y * wolf->move_speed;
		if (wolf->dir.y <= 0)
			if (!wolf->map.data[(int)(wolf->start.x)][(int)(wolf->start.y +
				wolf->dir.y * wolf->move_speed - 0.1)])
				wolf->start.y += wolf->dir.y * wolf->move_speed;
	}
	else
		down(wolf);
}

static void	left_right(t_wolf *w, int direction, double old_dir_x,
	double old_pl_x)
{
	if (direction < 0)
	{
		w->dir.x = w->dir.x * cos(w->rot_speed) -
			w->dir.y * sin(w->rot_speed);
		w->dir.y = old_dir_x * sin(w->rot_speed) +
			w->dir.y * cos(w->rot_speed);
		w->plane.x = w->plane.x * cos(w->rot_speed) -
			w->plane.y * sin(w->rot_speed);
		w->plane.y = old_pl_x * sin(w->rot_speed) +
			w->plane.y * cos(w->rot_speed);
	}
	else
	{
		w->dir.x = w->dir.x * cos(-w->rot_speed) -
			w->dir.y * sin(-w->rot_speed);
		w->dir.y = old_dir_x * sin(-w->rot_speed) +
			w->dir.y * cos(-w->rot_speed);
		w->plane.x = w->plane.x * cos(-w->rot_speed) -
			w->plane.y * sin(-w->rot_speed);
		w->plane.y = old_pl_x * sin(-w->rot_speed) +
			w->plane.y * cos(-w->rot_speed);
	}
}

void		manage(t_window *win, t_wolf *wolf)
{
	if (win->e.type == SDL_KEYDOWN)
	{
		if (win->e.key.keysym.sym == SDLK_UP)
			up_down(wolf, 1);
		if (win->e.key.keysym.sym == SDLK_DOWN)
			up_down(wolf, -1);
		if (win->e.key.keysym.sym == SDLK_LEFT)
			left_right(wolf, -1, wolf->dir.x, wolf->plane.x);
		if (win->e.key.keysym.sym == SDLK_RIGHT)
			left_right(wolf, 1, wolf->dir.x, wolf->plane.x);
	}
}
