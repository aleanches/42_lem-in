/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:53:47 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/10 13:54:10 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_valid_int(int val_i, char *val_c)
{
	char	*cur_val;
	int		res;

	res = 0;
	cur_val = ft_itoa(val_i);
	if (ft_strcmp(cur_val, val_c) == 0)
		res = 1;
	if (cur_val)
		free(cur_val);
	return (res);
}
