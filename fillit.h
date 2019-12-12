/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:20:36 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/12 14:24:18 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 1000

typedef struct	s_map
{
	int		size;
	char	**map;
}				t_map;

typedef struct	s_tetri
{
	int		width;
	int		height;
	char	abc;
	char	**arr;
}				t_etri;

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

int				ft_check_chars(char *buf);
int				ft_check_connection(char *buf);
int				ft_verify(char *buf);
t_list			*ft_read(char *buf, int nb_pieces);
t_etri			*find_piece(char *buf, char cur);
void			free_tetris(t_etri *tetris, size_t size);
t_list			*del_lst(t_list **lst);
void			solve(t_list *lst, int nb_pieces);
t_etri			*new_tetris(char **arr, int height, int width, char cur);
void			start_end(char *str, t_point *start, t_point *end);
t_point			*new_point(int x, int y);
int				ft_sqrt(int n);
void			free_map(t_map *map);
t_map			*new_map(int side_len);
int				solve_backtrack(t_list *lst, t_map *map);
void			map_print(t_map *map);

#endif
