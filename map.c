/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 09:42:09 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 17:22:57 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
/*			printf("\n---\nplace_piece\n");
			printf("\ntetris->arr[j][i]: %c\n", tetris->arr[j][i]);
			printf("point->y: %d, point->x: %d\n", point->y, point->x);
			printf("i (x): %d, j (y): %d\n", i, j);
			printf("start->y + j: %d, start->x + i: %d\n", point->y + j, point->x + i);
			printf("map->map[point->y + j][point->x + i]: %c\n---\n", map->map[point->y + j][point->x + i]);*/
			if (tetris->arr[j][i] == '#')
			{
				map->map[point->y + j][point->x + i] = c;
/*				if (map->map[point->y + j][point->x + i] == c)
					printf("placing %c successful\n", c);
				else
					printf("placing %c not successful\n", c);
				map_print(map);
				printf("\n");*/
			}
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int		check_map_spot(t_map *map, t_etri *tetris, int x, int y)
{
	int i; //y
	int j;

/*	printf("\nchar: %c\n", tetris->abc);
	for (int k = 0; k < tetris->height; k++) {
		printf("%s\n", tetris->arr[k]);
	}*/
	i = 0;
	if (map->map[y][x] != '.')
		return (0);
	while (i < tetris->height)
	{
		j = 0;
		while (j < tetris->width)
		{
/*			printf("\n---\ncheck_map_spot\n");
			printf("tetris char: %c\n", tetris->arr[i][j]);
			printf("map char: %c\n---\n", map->map[y + i][x + j]);*/
			if (tetris->arr[i][j] == '#' && map->map[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
/*	printf("END X: %d\n", x);
	printf("Placing piece\n");*/
	place_piece(map, tetris, new_point(x, y), tetris->abc);
	return (1);
}
