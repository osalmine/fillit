/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 09:42:09 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/16 11:39:58 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	return (0);
}

t_map	*new_map(int side_len)
{
	int		i;
	int		j;
	t_map	*new_map;

	new_map = (t_map*)malloc(sizeof(t_map));
	new_map->map = (char**)malloc(sizeof(char*) * side_len);
	new_map->size = side_len;
	i = 0;
	while (i < side_len)
	{
		j = 0;
		new_map->map[i] = ft_strnew(side_len);
		while (j < side_len)
		{
			new_map->map[i][j] = '.';
			j++;
		}
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
//	if (map->map[y][x] != '.')
//		return (0);
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
