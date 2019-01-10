/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:30:18 by kmieshko          #+#    #+#             */
/*   Updated: 2018/12/17 18:30:19 by kmieshko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	count_col(char *line)
{
	int		col;
	int		i;

	col = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '6')
		{
			while (line[i + 1] != ' ' && line[i + 1])
				i++;
			col++;
		}
		i++;
	}
	return (col);
}

static int	count_rows(int fd, char *line, t_map *map)
{
	int col;
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (get_next_line_fast(fd, &line))
	{
		col = count_col(line);
		if (col != map->col || !col)
		{
			ft_strdel(&line);
			error("Wrong map");
		}
		rows++;
		ft_strdel(&line);
	}
	return (rows);
}

static void	count_col_and_rows(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		error(strerror(errno));
	if (get_next_line_fast(fd, &line) <= 0)
		error("Wrong map");
	map->col = count_col(line);
	map->rows = 1 + count_rows(fd, line, map);
	if (!map->col)
		error("Wrong map");
	if (map->col < 3 || map->rows < 3)
		error("Need to add the columns or the rows!"
			"Minimum size of the map is 3 x 3");
	ft_strdel(&line);
	close(fd);
}

static void	fill_data_map(int j, int i, char *filename, t_map *map)
{
	int		fd;
	char	**tmp;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		error(strerror(errno));
	map->data = (int **)malloc(sizeof(int *) * map->rows);
	j = 0;
	while (get_next_line_fast(fd, &line))
	{
		map->data[j] = (int *)malloc(sizeof(int) * map->col);
		tmp = ft_strsplit(line, ' ');
		free(line);
		i = 0;
		while (tmp[i] != NULL)
		{
			map->data[j][i] = ft_atoi(tmp[i]) > NB_TEXT ? 1 : ft_atoi(tmp[i]);
			free(tmp[i]);
			i++;
		}
		free(tmp);
		j++;
	}
	close(fd);
}

void		parse_map(char *filename, t_map *map, int j, int i)
{
	count_col_and_rows(filename, map);
	fill_data_map(0, 0, filename, map);
	j = -1;
	while (++j < map->rows)
	{
		i = -1;
		while (++i < map->col)
		{
			if (map->data[0][i] == 0)
			{
				map->data[0][i] = 1;
				i = -1;
			}
			else if (map->data[map->rows - 1][i] == 0)
			{
				map->data[map->rows - 1][i] = 1;
				i = -1;
			}
			if (map->data[j][0] == 0)
				map->data[j][0] = 1;
			else if (map->data[j][map->col - 1] == 0)
				map->data[j][map->col - 1] = 1;
		}
	}
}
