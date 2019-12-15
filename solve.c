/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:38 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 11:24:21 by osalmine         ###   ########.fr       */
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
	printf("s->y: %d, s->x: %d\n", start->y, start->x);
	return (start);
}

int		solve_backtrack(t_list *lst, t_map *map)
{
	int		y;
	int		x;
	t_point	*start;
	t_etri	*tetris;

	y = 0;
	tetris = (t_etri *)(lst->content);
	start = start_pos(map);
	while (start->y <= map->size - tetris->height)
	{
		x = 0;
		while (start->x <= map->size - tetris->width)
		{
			if (check_map_spot(map, tetris, start))
				if (solve_backtrack(lst->next, map))
					return (1);
			x++;
		}
		y++;
	}
	return (1);
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
