/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:29:50 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/02 19:29:55 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/day2.h"

static void init_game(t_game *game)
{
    game->id = 0;
    game->red = 0;
    game->blue = 0;
    game->green = 0;
}

static int id_game(char *str)
{
    int i = 0;
    int id = 0;
    while(str[i])
    {
        if(ft_isdigit(str[i]))
            id = (id * 10) + (str[i] - '0');
        i++;
    }
    return (id);
}

static void count_color(char *str, t_game *game)
{
    int i = 0;
    int temp;
    while(str[i])
    {
        temp = 0;
        while(str[i] && !ft_isdigit(str[i]))
            i++;
        while(str[i] && ft_isdigit(str[i]))
        {
            temp = (temp * 10) + (str[i] - '0');
            i++;
        }
        while(str[i] && (str[i] == ' ' || str[i] == ','))
            i++;
        if(str[i] == 'r')
            if(temp > game->red)
                game->red = temp;
        if(str[i] == 'b')
            if(temp > game->blue)
                game->blue = temp;
        if(str[i] == 'g')
            if(temp > game->green)
                game->green = temp;
        if (str[i])
            i++;
    }
}

int main(void)
{
    t_game game;
    int fd = open("rscs/input.txt", O_RDONLY);
    int total = 0;
    char *line;
    int i;

    while((line = get_next_line(fd)))
    {
        init_game(&game);
        char **split = ft_split_str(line, ";:");
        
        free(line);

        game.id = id_game(split[0]);
        ft_printf("id : %d\n", game.id);
        i = 1 ;
        while(split[i])
        {
            count_color(split[i], &game);
            i++;
        }
        ft_free_split(split);
        ft_printf("red: %d\nblue: %d\ngreen: %d\n", game.red, game.blue, game.green);
        if(game.red <= 12 && game.blue <= 14 && game.green <= 13)
            total += game.id;
    }
    ft_printf("total : %d\n", total);
    return (0);
}
