/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 09:42:09 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 13:18:02 by osalmine         ###   ########.fr       */
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

void	place_piece(t_map *map, t_etri *tetris, t_point *start, char c)
{
	int i;
	int j;

	j = 0;
	while (j < tetris->width)
	{
		i = 0;
		while (i < tetris->height)
		{
			printf("\n---\nplace_piece\n");
			printf("\ntetris->arr[i][j]: %c\n", tetris->arr[i][j]);
			printf("start->y: %d, start->x: %d\n", start->y, start->x);
			printf("i: %d, j: %d\n", i, j);
			printf("start->y + i: %d, start->x + j: %d\n", start->y + i, start->x + j);
			printf("map->map[start->y + i][start->x + j]: %c\n---\n", map->map[start->y + i][start->x + j]);
			if (tetris->arr[i][j] == '#')
				map->map[start->y + i][start->x + j] = c;
			i++;
		}
		j++;
	}
//	ft_memdel((void**)&start);
}

/*int     check(t_map *map, t_etri *piece, int curx, int cury)
{
    int x;
// curx + cury || cur_pos
    x = 0;
    if (map[curx][cury] == ".")
        x++;
    if ((curx + piece->arr[2] > map->size) || (cury + piece->pos[3] > map->size))
        return (0);
    if (map[curx + piece->arr[2]][cury + piece->arr[3]] == ".")
        x++;
    if ((curx + piece->arr[4] > map->size) || (cury + piece->arr[5] > map->size))
        return (0);
    if (map->map[curx + piece->arr[4]][cury + piece->arr[5]] == ".")
        x++;
    if ((curx + piece->arr[6] > map->size) || (cury + piece->arr[7] > map->size))
        return (0);
    if (map->map[curx + piece->arr[6]][cury + piece->arr[7]] == ".")
        x++;
    if (x == 4)
        return (1);
    return (0);
}*/

int		check_map_spot(t_map *map, t_etri *tetris, t_point *start)
{
	int y;
	int x;

	printf("\nchar: %c\n", tetris->abc);
	for (int j = 0; j < tetris->height; j++) {
		printf("%s\n", tetris->arr[j]);
	}
	y = 0;
	if (map->map[start->y][start->x] != '.')
		return (0);

	while (y < tetris->height)
	{
		x = 0;
		while (x < tetris->width)
		{
			printf("\n---\ncheck_map_spot\n");
			printf("tetris char: %c\n", tetris->arr[y][x]);
			printf("map char: %c\n---\n", map->map[start->y + y][start->x + x]);
			if (tetris->arr[y][x] == '#' && map->map[start->y + y][start->x + x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	place_piece(map, tetris, start, tetris->abc);
	return (1);
}
