/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_chars_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:31:15 by vsanta            #+#    #+#             */
/*   Updated: 2019/11/10 18:20:52 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip_chars_i(char *line, char *skip_chars)
{
	int i;

	i = 0;
	while (line[i] && ft_strchr(skip_chars, line[i]))
		i++;
	return (i);
}
