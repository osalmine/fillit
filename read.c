/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:14:40 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 17:22:36 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

void	free_tetris(t_etri *tetris)
{
	int y;

	y = 0;
	while (y < tetris->height)
		ft_strdel(&(tetris->arr[y++]));
	ft_memdel((void**)&(tetris->arr));
	ft_memdel((void**)&tetris);
}

t_list	*del_lst(t_list *lst)
{
	t_list *ptr;

	while (lst)
	{
		ptr = lst->next;
		free_tetris((t_etri*)lst->content);
		free(lst);
		lst = ptr;
	}
	lst = NULL;
	return (NULL);
}

t_etri	*find_piece(char *buf, char cur)
{
	t_etri	*tetris;
	t_point *start;
	t_point *end;
	int		i;
	char	**arr;

	i = 0;
	start = new_point(0, 0);
	end = new_point(3, 3);
	start_end(buf, start, end);
//	printf("buf:\n%s\n", buf);
//	printf("start->x: %d, start->y: %d, end->x: %d, end->y: %d\n", start->x, start->y, end->x, end->y);
	arr = (char**)malloc(sizeof(char*) * (end->y - start->y + 1));
//	printf("malloced for rows is: %d\n", end->y - start->y + 1);
	while (i <= end->y - start->y)
	{
		arr[i] = ft_strnew(end->x - start->x + 1);
//		printf("malloced for chars is: %d\n", end->x - start->x + 1);
		ft_strncpy(arr[i], buf + start->x + (i + start->y) * 5, \
			end->x - start->x + 1);
//		printf("arr[%d]:\n%s\n", i, arr[i]);
		i++;
	}
	tetris = new_tetris(arr, end->y - start->y + 1, end->x - start->x + 1, cur);
	ft_memdel((void**)&start);
	ft_memdel((void**)&end);
	return (tetris);
}

t_list	*ft_read(char *buf, int nb_pieces)
{
	t_list	*lst;
	t_etri	*tetris;
	char	cur;
	char	*temp;
	char	*str;

	cur = 'A';
	str = ft_strdup(buf);
	lst = NULL;
	while (nb_pieces--)
	{
		if (!(temp = ft_strsub(str, 0, 21)))
		{
			ft_strdel(&temp);
			return (NULL);
		}
		if (!(tetris = find_piece(temp, cur++)))
		{
			ft_strdel(&temp);
			return (del_lst(lst));
		}
		ft_lstadd(&lst, ft_lstnew(tetris, sizeof(t_etri)));
		ft_strdel(&temp);
		ft_memdel((void**)&tetris);
		if (!(str = ft_strdup(str + 21)))
			break ;
	}
	ft_strdel(&temp);
	ft_strdel(&str);
	ft_lstrev(&lst);
//	program gives read error later with this while loop, as the list is NULL at the end
//	of this

/*	t_etri *t;
	while (lst)
	{
		t = (t_etri*)lst->content;
		printf("char: %c\n", t->abc);
		for (int j = 0; j < t->height; j++) {
			printf("%s\n", t->arr[j]);
		}
		lst = lst->next;
	}*/
	return (lst);
}
