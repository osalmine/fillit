/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 09:42:09 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/12 14:46:28 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		start_x(char *str, t_etri *tetris)
{
	int x;

	x = ft_strchri(str, '.');
//	printf("strchri found first x spot: %d\n", x);
	if (x == -1)
		x = 0;
	else if (tetris->width == 3 && tetris->arr[0][0] == '.' && x >= 2)
	{
//		printf("1st: tetris is 3 wide, its first character is '.' and x >= 2\n");
		x -= 2;
//		printf("x is now %d\n", x);
	}
	else if (tetris->width == 2 && tetris->arr[0][0] == '.' && x >= 1)
	{
//		printf("2nd: tetris is 2 wide, its first character is '.' and x >= 2\n");
		x -= 1;
//		printf("x is now %d\n", x);
	}
	return (x);
}

int		ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
//	printf("current map row: %s\n", s);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
//			printf("strchri place i (%d) found: %c\n", i, s[i]);
			return (i);
		}
		i++;
	}
	return (-1);
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
/*	if (c != '.')
		printf("PLACED TETRIS PIECE:\n");
	else
		printf("REMOVED TETRIS PIECE:\n");
	for (int k = 0; k < tetris->height; k++) {
		printf("%s\n", tetris->arr[k]);
	}*/
	while (i < tetris->width)
	{
		j = 0;
		while (j < tetris->height)
		{
//			printf("Character at tetris arr [j (%d)][i (%d)] : %c\n", j, i, tetris->arr[j][i]);
			if (tetris->arr[j][i] == '#')
			{
//				printf("Placed char to point y: %d, x: %d\n", point->y + j, point->x + i);
				map->map[point->y + j][point->x + i] = c;
			}
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

//	printf("check fitting from point x: %d, y: %d\n", x - 1, y - 1);
	i = 0;
	while (i < tetris->height)
	{
		j = 0;
		while (j < tetris->width)
		{
			if (tetris->arr[i][j] == '#' && map->map[y + i][x + j] != '.')
			{
//				printf("map row (%d) is: %s\n", y + i,  map->map[y + i]);
//				printf("map spot is invalid: map[y (%d) + i (%d)][x (%d) + j (%d)] : %c\n\n", y, i, x, j, map->map[y + i][x + j]);
				return (0);
			}
			j++;
		}
//		printf("map row is valid: %s\n", map->map[y + i]);
		i++;
	}
	place_piece(map, tetris, new_point(x, y), tetris->abc);
//	printf("map spot is valid, placed piece %c\n\n", tetris->abc);
	return (1);
}
