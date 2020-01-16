/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 09:42:09 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/16 12:43:23 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		start_x(char *str, t_etri *tetris)
{
	int x;

	x = ft_strchri(str, '.');
	if (x == -1)
		x = 0;
	else if (tetris->width == 3 && tetris->arr[0][0] == '.' && x >= 2)
		x -= 2;
	else if (tetris->width == 3 && tetris->arr[0][0] == '.' && x >= 1)
		x -= 1;
	else if (tetris->width == 2 && tetris->arr[0][0] == '.' && x >= 1)
		x -= 1;
	return (x);
}

int		ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}

t_map	*new_map(int side_len)
{
	int		i;
	int		j;
	t_map	*new_map;

	if (!(new_map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(new_map->map = (char**)malloc(sizeof(char*) * side_len)))
		return (NULL);
	new_map->size = side_len;
	i = 0;
	while (i < side_len)
	{
		j = 0;
		new_map->map[i] = ft_strnew(side_len);
		while (j < side_len)
			new_map->map[i][j++] = '.';
		i++;
	}
	return (new_map);
}

void	place_piece(t_map *map, t_etri *tetris, t_point *point, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
			if (tetris->arr[j][i] == '#')
				map->map[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int		check_map_spot(t_map *map, t_etri *tetris, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetris->height)
	{
		j = 0;
		while (j < tetris->width)
		{
			if (tetris->arr[i][j] == '#' && map->map[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place_piece(map, tetris, new_point(x, y), tetris->abc);
	return (1);
}
