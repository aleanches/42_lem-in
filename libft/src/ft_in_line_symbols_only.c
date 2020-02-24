/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_line_symbols_only.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:44:19 by vsanta            #+#    #+#             */
/*   Updated: 2019/11/10 18:22:18 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in_line_symbols_only(char *line, int n, char *symbols_only)
{
	int i;

	i = 0;
	while (line[i] && i < n)
	{
		if (ft_strchr(symbols_only, line[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}
