/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:16:05 by osalmine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/16 15:24:05 by osalmine         ###   ########.fr       */
=======
/*   Updated: 2019/12/16 14:49:02 by osalmine         ###   ########.fr       */
>>>>>>> a806709c1a9c01068952b430bd9203410384b29c
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_display_use(void)
{
	write(1, "usage: ./fillit [source_file]\n", 30);
	return (1);
}

int			main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	int		fd;
	int		nb_pieces;
	t_list	*lst;

	fd = 0;
	if (argc != 2)
		return (ft_display_use());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (write(1, "error\n", 6));
	buf[read(fd, buf, BUFF_SIZE)] = '\0';
	close(fd);
	if (!(nb_pieces = ft_verify(buf)))
		return (write(1, "error\n", 6));
	if (!(lst = ft_read(buf, nb_pieces)))
		return (write(1, "error\n", 6));
	solve(lst, nb_pieces);
	return (0);
}
