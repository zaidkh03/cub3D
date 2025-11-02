/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 05:54:13 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 05:54:30 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(char const **s, char c)
{
	size_t	len;
	char	*res;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	while (**s && **s != c)
	{
		res[len] = **s;
		len++;
		(*s)++;
	}
	res[len] = '\0';
	return (res);
}

static int	fill_words(char **arr, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		arr[i] = copy_word(&s, c);
		if (!arr[i])
		{
			arr[i] = NULL;
			return (0);
		}
		i++;
	}
	arr[i] = NULL;
	return (1);
}

static void	free_parts(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!fill_words(arr, s, c))
	{
		free_parts(arr);
		return (NULL);
	}
	return (arr);
}
