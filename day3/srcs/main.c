/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:18:25 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/03 15:41:23 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/day3.h"

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

// line2 est celle que je verif grace au line1 et line3
static void process(char *line1, char *line2, char *line3)
{
    int flag;
    int somme;
    int i = 0;
    int j = 0;
    int len = 0;
    while(line2[i])
    {
        somme = 0;
        j = 0;
        flag = 0;
        while(line2[i] && !ft_isdigit(line2[i]))
            i++;
        while(line2[i + j] && ft_isdigit(line2[i + j]))
        {
            somme *= 10;
            somme += line2[i + j] - '0';
            j++;
        }
        len = ft_int_len(somme);
        while(len--)
        {
            if(i == 0)
                if(line1[i] == '*' || line3[i] == '*')
                    flag = 1;
            i++;
        }
    }
}

int main(void)
{
    char *line = ft_read(open("rscs/input.txt", O_RDONLY));
    char **split = ft_split(line, '\n');
    free(line);
    int len = ft_splitlen((const char**)split);
    ft_printf("len : %d\n", len);
    int i = 0;
    while(i < len - 2)
    {
        process(split[i], split[i+1], split[i+2]);
        i++;
    }
    return (0);
}
