/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:22:51 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/08 14:45:05 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_c_count(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
	}
	return (i);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**buf;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	buf = (char**)malloc(sizeof(char*) * (ft_w_count(s, c) + 1));
	if (buf == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			buf[j] = ft_strsub(s, i, ft_c_count(&s[i], c));
			if (buf[j] == NULL)
				return ((char**)(long int)ft_array_free(&buf, 0));
			j++;
		}
		i++;
	}
	buf[j] = NULL;
	return (buf);
}
