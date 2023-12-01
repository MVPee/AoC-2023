/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:14:11 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/01 18:41:55 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/day1.h"

static int	ft_digitrchr(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	while (line[len])
	{
		if (ft_isdigit(line[len]))
			return (line[len]);
		len--;
	}
	return (0);
}

static int	ft_digitchr(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			return (line[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char			*line;
	int				fd;
	unsigned int	total;

    total = 0;
	fd = open("rscs/input.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		total += (ft_digitchr(line) - '0') * 10;
		total += ft_digitrchr(line) - '0';
		free(line);
	}
    ft_printf("total : %i\n", total);
	return (0);
}
