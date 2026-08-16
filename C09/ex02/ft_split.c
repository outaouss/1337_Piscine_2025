/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <outaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:11:22 by outaouss          #+#    #+#             */
/*   Updated: 2025/08/07 21:40:31 by outaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**free_arr(char **arr, int index_c)
{
	while (index_c > 0)
		free(arr[--index_c]);
	free(arr);
	return (NULL);
}

int	put_inside(char **new_str, const char *s, int *i, char c)
{
	int	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	new_str[0] = ft_substr(s, start, *i - start);
	if (!new_str[0])
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**new_string;
	int		i;
	int		word_index;

	if (s == NULL)
		return (NULL);
	new_string = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new_string)
		return (NULL);
	i = 0;
	word_index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!put_inside(&new_string[word_index], s, &i, c))
				return (free_arr(new_string, word_index));
			word_index++;
		}
	}
	new_string[word_index] = NULL;
	return (new_string);
}
