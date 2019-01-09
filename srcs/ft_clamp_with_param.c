/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp_with_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:05:02 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/20 14:05:05 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static double	if_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static double	if_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double			ft_clamp_with_param(double value, double min, double max)
{
	double res;

	res = if_min(max, if_max(min, value));
	return (res);
}
