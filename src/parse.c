/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:43:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/22 20:07:53 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int ft_lm_coment_type(char **line)
{
	if ((*line)[0] && (*line)[0] == '#' && ft_strcmp((*line), "##start") == 0)
		return (21);
	else if ((*line)[0] && (*line)[0] == '#' && ft_strcmp((*line), "##end") == 0)
		return (22);
	else if ((*line)[0] && (*line)[0] == '#')
		return (20);
	return (0);
}

int	ft_lm_is_not_room(int action, char **line, t_lm **lm)
{
	if ((*lm)->room_start == NULL || (*lm)->room_end == NULL)
		ft_lm_put_error(lm, ft_str_free(line, action));
	if (((*lm)->mtx = ft_lm_mtx_new((*lm)->rooms_c, '-')) == NULL)
		ft_lm_put_error(lm, ft_str_free(line, action));
	return (ft_lm_add_con(line, lm));
}

void	ft_lm_parse_input(t_lm **lm)
{
	char *line;
	int action;

	line = NULL;
	action = 10;
	while (f_get_next_line(0, &line))
	{
		ft_lst_push_back_data(&((*lm)->input), (void*)line);
		if (action == 10)
			action = ft_lm_set_count_ants(&line, lm);
		else if (action == 20 || action == 21 || action == 22)
			action = ft_lm_add_room(action, &line, lm);
		else if (action == 30)
			action = ft_lm_add_con(&line, lm);
	}
}
