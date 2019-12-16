/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:13:14 by osalmine          #+#    #+#             */
/*   Updated: 2019/12/16 14:47:22 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_check_chars(char *buf)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			k++;
		if (buf[i] == '\n')
			j++;
		i++;
	}
	if (k % 4 != 0 || k > 104 || k < 4 || (i - 20) % 21 != 0
		|| (j - 4) % 5 != 0)
		return (0);
	return (k);
}

int		ft_check_connection(char *buf)
{
	int piece;
	int i;

	piece = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				piece++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				piece++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				piece++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				piece++;
		}
		i++;
	}
	if (piece == 6 || piece == 8)
		return (1);
	return (0);
}

int		ft_verify(char *buf)
{
	char	*temp;
	char	*str;
	char	*ptr;

	str = ft_strdup(buf);
	while (*str)
	{
		if (!(temp = ft_strsub(str, 0, 21)))
		{
			ft_strdel(&temp);
			return (0);
		}
		if (!ft_check_connection(temp))
			return (0);
		ft_strdel(&temp);
		if (!(ptr = ft_strdup(str + 21)))
			break ;
		ft_strdel(&str);
		str = ptr;
		if (*(str + 1) == '\0')
			break ;
	}
	ft_strdel(&str);
	return (ft_check_chars(buf) / 4);
}
