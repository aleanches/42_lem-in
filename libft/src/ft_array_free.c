/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:54:21 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/08 14:44:15 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_free(char ***array, int ret_val)
{
	int i;

	i = 0;
	while (array && (*array) && (*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	if (array && (*array))
	{
		free(*array);
		*array = NULL;
	}
	return (ret_val);
}
