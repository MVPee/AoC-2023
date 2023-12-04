/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:53:03 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/04 20:27:36 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/day4.h"

static int count_win(char **split)
{
    int count;
    int i;

    count = 0;
    i = 1;
    while(split[i] && ft_strcmp(split[i], "|") != 0)
    {
        count++;
        i++;
    }
    return count;
}

static int count_num(char **split)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while(split[i] && ft_strcmp(split[i], "|") != 0)
        i++;
    i++;
    while(split[i])
    {
        i++;
        count++;
    }
    return count;
}

static int process(int *win_array, int *num_array)
{
    int total;
    int i, j;

    i = 0;
    j = 0;
    total = 0;
    while(win_array[i])
    {
        j = 0;
        while(num_array[j])
        {
            if(win_array[i] == num_array[j])
                if(total == 0)
                    total = 1;
                else
                    total <<= 1;
            j++;
        }
        i++;
    }
    return total;
}

static int parsing(char **split)
{
    int *win;
    int *num;
    int i, j;
    int total;

    win = (int *)malloc(sizeof(int) * (count_win(split) + 1));
    num = (int *)malloc(sizeof(int) * (count_num(split) + 1));

    i = 1;
    j = 0;
    while(split[i] && ft_strcmp(split[i], "|"))
        win[j++] = ft_atoi(split[i++]);
    win[j] = NULL;
    i++;
    j = 0;
    while(split[i])
        num[j++] = ft_atoi(split[i++]);
    
    total = process(win, num);
    free(win);
    free(num);
    return total;
}

int main(void)
{
    char *line;
    char **split;
    int i;
    int total = 0;
    int fd = open("rscs/input.txt", O_RDONLY);
    while(line = get_next_line(fd))
    {
        split = ft_split_str(line, " Card");
        free(line);
        i = 0;
        total += parsing(split);
        ft_free_split(split);
    }
    ft_printf("total %d\n", total);
    close(fd);
    return 0;
}