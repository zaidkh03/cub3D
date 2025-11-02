/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkhali <zalkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 05:54:39 by zalkhali          #+#    #+#             */
/*   Updated: 2025/11/02 05:54:41 by zalkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char *dst, const char *src, size_t *i)
{
	size_t	j;

	j = 0;
	while (src[j])
		dst[(*i)++] = src[j++];
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	copy_str(res, s1, &i);
	copy_str(res, s2, &i);
	res[i] = '\0';
	return (res);
}
