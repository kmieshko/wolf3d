/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:11:41 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/20 14:11:42 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_color(int color, double inten)
{
	int		red;
	int		green;
	int		blue;

	red = ft_clamp_with_param(round((color & 0xFF0000) >> 16) * inten, 0, 255);
	green = ft_clamp_with_param(round((color & 0xFF00) >> 8) * inten, 0, 255);
	blue = ft_clamp_with_param(round((color & 0xFF)) * inten, 0, 255);
	color = (red << 16) + (green << 8) + blue;
	return (color);
}
