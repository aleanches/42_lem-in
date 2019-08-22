/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_con.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:48 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/22 20:05:27 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

static char *ft_lm_mtx_row_new(int size, char def_val)
{
	char	*row;

	if ((row = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_memset((void*)row, def_val, sizeof(char) * size);
	row[size] = 0;
	return (row);
}

char **ft_lm_mtx_new(int size, char def_val)
{
	int		i;
	char	**col;

	i = 0;
	col = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		if ((col[i] = ft_lm_mtx_row_new(size, def_val)) == NULL)
			return ((char**)(long int)ft_array_free(&col, 0));
		i++;
	}
	col[size] = NULL;
	return (col);
}

int ft_lm_add_con(char **line, t_lm **lm)
{

	char	**tmp;
	int		from;
	int		to;

	if ((*line)[0] && (*line)[0] == '#')
		return (30);
	if ((tmp = ft_strsplit((*line), '-')) == NULL || ft_array_len(tmp) != 2)
		ft_lm_put_error(lm, ft_array_free(&tmp, 30));
	if ((from = ft_lm_get_room_by_name(*lm, tmp[0])) == -1 ||
		(to = ft_lm_get_room_by_name(*lm, tmp[1])) == -1)
		ft_lm_put_error(lm, ft_array_free(&tmp, 30));
	(*lm)->mtx[from][to] = '+';
	(*lm)->mtx[to][from] = '+';
	return (ft_array_free(&tmp, 30));
}
