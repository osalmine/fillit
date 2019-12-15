/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:38 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 13:10:18 by osalmine         ###   ########.fr       */
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
	t_point	*start;
	t_etri	*tetris;

	map_print(map);
	tetris = (t_etri *)(lst->content);
	start = start_pos(map);
	x = start->x;
	while (start->y <= map->size - tetris->height)
	{
		printf("s->y: %d, m->size - t->height: %d\n", start->y, map->size - tetris->height);
		start->x = x;
		while (start->x <= map->size - tetris->width)
		{
			printf("s->x: %d, m->size - t->width: %d\n", start->x, map->size - tetris->width);
			if (check_map_spot(map, tetris, start))
			{
				if (solve_backtrack(lst->next, map))
					return (1);
				else
					place_piece(map, tetris, start, '.');
				}
			start->x++;
		}
		start->y++;
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
	printf("\n---\n");
	while (!solve_backtrack(lst, map))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	printf("\nMAP:\n");
	map_print(map);
	free_map(map);
}
