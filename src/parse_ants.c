/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/09 15:49:58 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int ft_lm_set_count_ants(char **line, t_lm **lm)
{
	int count;
	if ((*line)[0] && (*line)[0] == '#')
		return (10);
	count = ft_atoi((*line));
	if (count == 0 || ft_is_valid_int(count, (*line)) == 0)
		ft_lm_put_error(lm, ft_str_free(line, 10));
	(*lm)->ants_c = count;
	return (20);
}
