/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:17:39 by kmieshko          #+#    #+#             */
/*   Updated: 2018/09/12 17:17:40 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_clean_new(char *str)
{
	char		*arr;
	int			i;

	i = ft_strchr_pos(str, '\n');
	if ((str[i] && !str[i + 1]) || !str[i])
	{
		ft_strdel(&str);
		return (NULL);
	}
	arr = ft_strdup(str + i + 1);
	ft_strdel(&str);
	return (arr);
}

int				get_next_line_fast(int fd, char **line)
{
	static char	*arr;
	char		buf[BUFF_SIZE + 1];
	int			i;

	if (BUFF_SIZE < 0 || !line || fd < 0)
		return (-1);
	if (!arr)
		arr = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(arr, '\n')))
	{
		if ((i = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[i] = '\0';
		arr = join(arr, buf);
		if (strcmp(arr, "\0") == 0)
			return (0);
		if (i == 0)
			break ;
	}
	if (!(*line = ft_strnew(ft_strlen(arr))))
		*line = NULL;
	i = ft_strchr_pos(arr, '\n');
	ft_strncpy(*line, arr, i);
	arr = ft_clean_new(arr);
	return (1);
}
