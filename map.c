/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 09:42:09 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 11:40:32 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	place_piece(t_map *map, t_etri *tetris, int x, int y, char c)
{
	
}

int		check_map_spot(t_map *map, t_etri *tetris, t_point *start)
{
	if (map->map[start->y][start->x] == '#')
		return (0);
	while (start->y <= map->size - tetris->height)
	{
		x = 0;
		while (start->x <= map->size - tetris->width)
		{

			x++;
		}
		y++;
	}
	return (1);
}
