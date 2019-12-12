/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:38 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/12 15:08:58 by osalmine         ###   ########.fr       */
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
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		solve_backtrack(t_list *lst, t_map *map)
{
	lst = NULL;
	map = NULL;
	if (map->size > 4)
		return (0);
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
	printf("\nMAP:\n");
	map_print(map);
	lst = NULL;
	while (!solve_backtrack(lst, map))
	{
		size++;
		free_map(map);
		map = new_map(size);
	}
	map_print(map);
	free_map(map);
}
