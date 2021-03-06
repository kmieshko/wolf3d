/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_person_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:03:32 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/20 14:03:33 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	find_person_position(t_wolf *wolf)
{
	int		y;
	int		x;
	int		flag;

	y = wolf->map.rows - 1;
	flag = 0;
	while (y > 0)
	{
		x = wolf->map.col - 1;
		while (x > 0)
		{
			if (wolf->map.data[y][x] == 0 && flag == 0)
			{
				wolf->start.y = x + 0.5;
				wolf->start.x = y + 0.5;
				flag = 1;
				return ;
			}
			x--;
		}
		y--;
	}
	if (flag == 0)
		error("No place for the personage found");
}
