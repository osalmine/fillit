/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:38 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/12 14:46:14 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	map_print(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
		ft_putendl(map->map[i++]);
}

int		start_y(t_map *map)
{
	int	y;
	int i;

	y = 0;
	i = 0;
	while (i < map->size)
	{
		if (ft_strchri(map->map[y], '.') != -1)
		{
			y = i;
			break ;
		}
		i++;
	}
	return (y);
}

int		solve_backtrack(t_list *lst, t_map *map)
{
	int		x;
	int		y;
	t_etri	*tetris;

	if (lst == NULL)
		return (1);
	tetris = (t_etri *)(lst->content);
//	map_print(map);
//	printf("\n");
//	printf("checking for valid starting point for piece %c\n", tetris->abc);
	y = start_y(map);
//	printf("start y: %d\n", y);
	while (y <= map->size - tetris->height)
	{
//		printf("\n1st while loop. y (%d) <= m->size (%d) - t->height (%d) (= %d)\n", y, map->size, tetris->height, map->size - tetris->height);
//		x = start_x(map->map[y], tetris);
		x = 0;
//		printf("start x: %d\n\n", x);
		while (x <= map->size - tetris->width)
		{
//			printf("2nd while loop. x (%d) <= m->size (%d) - t->width (%d) (= %d)\n\n", x, map->size, tetris->width, map->size - tetris->width);
			if (check_map_spot(map, tetris, x, y))
			{
				if (solve_backtrack(lst->next, map))
					return (1);
				else
				{
//					printf("removing piece %c\n", tetris->abc);
//					map_print(map);
					place_piece(map, tetris, new_point(x, y), '.');
//					printf("\n");
				}
			}
			x++;
		}
//		printf("Failed 2nd while loop. x (%d) <= m->size (%d) - t->width (%d) (= %d)\n\n", x, map->size, tetris->width, map->size - tetris->width);
		y++;
	}
//	printf("solve failed in piece %c with map size %d\n", tetris->abc, map->size);
//	printf("y (%d) <= m->size (%d) - t->height (%d) (= %d)\n", y, map->size, tetris->height, map->size - tetris->height);
	return (0);
}

int		ft_sqrt(int n)
{
	int res;

	res = 2;
	while (res * res < n)
		res++;
	return (res);
}

void	solve(t_list *lst, int nb_pieces)
{
	int		size;
	t_map	*map;

	size = ft_sqrt(nb_pieces * 4);
	map = new_map(size);
	while (!solve_backtrack(lst, map))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	map_print(map);
	free_map(map);
}
