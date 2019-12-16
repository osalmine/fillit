/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:14:40 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/16 11:48:46 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	start = new_point(3, 3);
	end = new_point(0, 0);
	start_end(buf, start, end);
	arr = (char**)malloc(sizeof(char*) * (end->y - start->y + 1));
	while (i <= end->y - start->y)
	{
		arr[i] = ft_strnew(end->x - start->x + 1);
		ft_strncpy(arr[i], buf + start->x + (i + start->y) * 5, \
			end->x - start->x + 1);
		i++;
	}
	tetris = new_tetris(arr, end->y - start->y + 1, end->x - start->x + 1, cur);
	ft_memdel((void**)&start);
	ft_memdel((void**)&end);
	return (tetris);
}

t_list	*read_piece(t_list *lst, char *str, char cur)
{
	char	*temp;
	t_etri	*tetris;

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
	ft_strdel(&temp);
	return (lst);
}

t_list	*ft_read(char *buf, int nb_pieces)
{
	t_list	*lst;
	char	cur;
	char	*str;

	cur = 'A';
	str = ft_strdup(buf);
	lst = NULL;
	while (nb_pieces--)
	{
		lst = read_piece(lst, str, cur++);
		if (!(str = ft_strdup(str + 21)))
			break ;
	}
	ft_strdel(&str);
	ft_lstrev(&lst);
	return (lst);
}
