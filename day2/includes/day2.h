/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:30:16 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/02 17:46:31 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAY2_H
# define DAY2_H

# include "../../libft/includes/libft.h"

typedef struct s_game
{
	int	id;
	int	red;
	int	blue;
	int	green;
}		t_game;

char	**ft_split_str(char *str, char *charset);

#endif