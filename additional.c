/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:51:12 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/12 13:58:30 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_etri	*new_tetris(char **arr, int height, int width, char cur)
{
	t_etri *tetris;

	tetris = (t_etri*)malloc(sizeof(t_etri));
	tetris->height = height;
	tetris->width = width;
	tetris->abc = cur;
	tetris->arr = arr;
	return (tetris);
}

t_point	*new_point(int x, int y)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
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

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_strdel(&map->map[i]);
		i++;
	}
	ft_memdel((void**)&map->map);
	ft_memdel((void**)&map);
}

void	start_end(char *str, t_point *start, t_point *end)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			start->x = i % 5;
			start->y = i / 5;
			break ;
		}
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '#')
		{
			end->x = i % 5;
			end->y = i / 5;
			break ;
		}
		i--;
	}
}
