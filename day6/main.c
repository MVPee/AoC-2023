/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:08:39 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/06 18:35:28 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static int process_course(int time, int distance)
{
    int i = 1;
    int temp = 0;
    int total = 0;
    ft_printf("%d %d\n", time, distance);
    while(i < time)
    {
        temp = (time - i) * i;
        if(temp > distance)
            total++;
        i++;
    }
    if(total == 0)
        return 1;
    return total;
}

int main(void)
{
    int fd = open("input.txt", O_RDONLY);
    char *str = ft_read(fd);
    char **split = ft_split(str, ' ');
    int total = 1;
    total *= process_course(59, 543);
    ft_printf("total: %d\n", total);
    total *= process_course(68, 1020);
    ft_printf("total: %d\n", total);
    total *= process_course(82, 1664);
    ft_printf("total: %d\n", total);
    total *= process_course(74, 1022);
    ft_printf("total: %d\n", total);
    return 0;
}