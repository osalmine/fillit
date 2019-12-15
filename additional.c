/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:51:12 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 09:42:47 by osalmine         ###   ########.fr       */
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

void		ft_lstrev(t_list **list)
{
	t_list *cur;
	t_list *next;
	t_list *prev;

	prev = NULL;
	cur = *list;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*list = prev;
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
