/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:40:24 by mvpee             #+#    #+#             */
/*   Updated: 2023/12/02 17:50:02 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/day2.h"

int	separator_check(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	total_string(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && separator_check(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !separator_check(str[i], charset))
			i++;
	}
	return (count);
}

int	sep_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !separator_check(str[i], charset))
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = sep_len(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_str(char *str, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	if (!str || !charset)
		return (0);
	strings = (char **)malloc(sizeof(char *)
			* (total_string(str, charset) + 1));
	if (!strings)
		return (0);
	while (*str)
	{
		while (*str && separator_check(*str, charset))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !separator_check(*str, charset))
			str++;
	}
	strings[i] = NULL;
	return (strings);
}
