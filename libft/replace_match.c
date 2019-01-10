/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:54:23 by kmieshko          #+#    #+#             */
/*   Updated: 2018/10/25 15:54:24 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_match(char *str, char c)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_str = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i + 1] && str[i + 1] != c) || str[i] != c)
		{
			new_str[j] = str[i];
			j++;
		}
		else if (i == ft_strlen(str) - 1)
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	ft_strdel(&str);
	return (new_str);
}
