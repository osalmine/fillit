/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:38 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 14:45:39 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	map_print(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->map[i]);
		i++;
	}
}

t_point	*start_pos(t_map *map)
{
	int		i;
	t_point	*start;

	i = 0;
	start = new_point(0, 0);
	while (i < map->size)
	{
		if ((start->x = ft_strchri(map->map[i], '.')))
		{
			start->y = i;
			break ;
		}
		i++;
	}
	return (start);
}

int		solve_backtrack(t_list *lst, t_map *map)
{
	int		x;
	int		y;
	t_point	*start;
	t_etri	*tetris;

	if (lst == NULL)
		return (1);
	tetris = (t_etri *)(lst->content);
	start = start_pos(map);
//	x = start->x;
//	y = start->y;
	y = 0;
	while (y <= map->size - tetris->height)
	{
//		printf("y: %d, m->size - t->height: %d\n", y, map->size - tetris->height);
//		x = start->x;
		x = 0;
		while (x <= map->size - tetris->width)
		{
//			printf("x: %d, m->size - t->width: %d\n", x, map->size - tetris->width);
			if (check_map_spot(map, tetris, x, y))
			{
				if (solve_backtrack(lst->next, map))
					return (1);
				else
					place_piece(map, tetris, new_point(x, y), '.');
				}
			x++;
		}
		y++;
	}
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
//	printf("\n---\n");
	while (!solve_backtrack(lst, map))
	{
		printf("ok\n");
		size++;
		free_map(map);
		map = new_map(size);
	}
//	printf("\nMAP:\n");
	map_print(map);
	free_map(map);
}
