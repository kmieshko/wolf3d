/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:09:44 by kmieshko          #+#    #+#             */
/*   Updated: 2018/08/06 14:09:45 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

static int	ft_get_sign(const char *str)
{
	int		sign;
	int		i;
	i = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' \
			|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	return (sign);
}

double		ft_atod(char *str)
{
	double	n;
	int		flag;
	char	**arr;

	flag = 1;
	if (!(ft_strchr(str, '.')))
		return (ft_atoi(str));
	else
	{
		arr = ft_strsplit(str, '.');
		n = ft_atoi(arr[0]);
		flag = (ft_get_sign(str) < 0) ? -1 : 1;
		if (n < 0)
			n = -n;
		if (!(arr[1][0] >= '0' && arr[1][0] <= '9'))
			return (0);
		if (ft_atoi(arr[1]) >= 0)
			n += (double)ft_atoi(arr[1]) /
				ft_recursive_power(10, ft_strlen(arr[1]));
		else
			n = 0;
		ft_free(arr);
	}
	return (n * flag);
}
