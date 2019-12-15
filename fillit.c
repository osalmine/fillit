/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:16:05 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/15 15:06:17 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_display_use(void)
{
	write(2, "usage: ./fillit [source_file]\n", 30);
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
		return (write(2, "fd error\n", 9));
	buf[read(fd, buf, BUFF_SIZE)] = '\0';
	close(fd);
	if (!(nb_pieces = ft_verify(buf)))
		return (write(2, "verify error\n", 13));
	if (!(lst = ft_read(buf, nb_pieces)))
		return(write(2, "read error\n", 11));
	solve(lst, nb_pieces);
//	printf("\nChecking leaks...\n");
//	while (1) ;
	return (0);
}
