/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_con.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:48 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/10 14:29:01 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int ft_lm_add_con(char **line, t_lm **lm)
{

	char	**tmp;
	int		from;
	int		to;

	if ((*line)[0] && (*line)[0] == '#')
		return (30);
	if ((tmp = ft_strsplit((*line), '-')) == NULL || ft_array_len(tmp) != 2)
		ft_lm_put_error(lm, ft_str_free(line, ft_array_free(&tmp, 30)));
	if ((from = ft_lm_get_room_i(*lm, tmp[0])) == -1 ||
		(to = ft_lm_get_room_i(*lm, tmp[1])) == -1)
		ft_lm_put_error(lm, ft_str_free(line, ft_array_free(&tmp, 30)));
	(*lm)->mtx[from][to] = '+';
	(*lm)->mtx[to][from] = '+';
	return (ft_array_free(&tmp, 30));
}