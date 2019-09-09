/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:43:42 by vsanta            #+#    #+#             */
/*   Updated: 2019/09/07 13:31:35 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

static int		ft_lm_add_ants(char **line, t_lm **lm)
{
	int count;

	if ((*line)[0] && (*line)[0] == '#')
		return (10);
	count = ft_atoi((*line));
	if (count < 1 || ft_is_valid_int(count, (*line)) == 0)
		ft_lm_put_error(lm, 10);
	(*lm)->ants_c = count;
	(*lm)->ants = ft_lm_ants_new(lm);
	return (20);
}

static int		ft_lm_add_room(int action, char **line, t_lm **lm)
{
	char	**tmp;
	t_room	*new_room;

	if (ft_lm_coment_type(line) != 0)
		return (ft_lm_coment_type(line));
	if ((action == 21 && (*lm)->room_start != NULL) ||
		(action == 22 && (*lm)->room_end != NULL))
		ft_lm_put_error(lm, action);
	if ((tmp = ft_strsplit((*line), ' ')) == NULL)
		ft_lm_put_error(lm, action);
	if (ft_array_len(tmp) != 3 || tmp[0][0] == 'L' ||
		ft_lm_room_find_by_name(*lm, tmp[0]) != -1 ||
		(new_room = ft_lm_room_new(tmp)) == NULL)
		return (ft_lm_is_not_room(ft_array_free(&tmp, action), line, lm));
	ft_str_free(&(tmp[1]), ft_str_free(&(tmp[2]), action));
	free(tmp);
	if (action == 21)
		(*lm)->room_start = ft_lm_room_add_new(lm, new_room);
	else if (action == 22)
		(*lm)->room_end = ft_lm_room_add_new(lm, new_room);
	else
		ft_lm_room_add_new(lm, new_room);
	return (20);
}

int				ft_lm_add_con(char **line, t_lm **lm)
{
	char	**tmp;
	int		from;
	int		to;

	if ((*line)[0] && (*line)[0] == '#')
		return (30);
	if ((tmp = ft_strsplit((*line), '-')) == NULL || ft_array_len(tmp) != 2)
		ft_lm_put_error(lm, ft_array_free(&tmp, 30));
	from = ft_lm_room_find_by_name(*lm, tmp[0]);
	to = ft_lm_room_find_by_name(*lm, tmp[1]);
	if (from == -1 || to == -1)
		ft_lm_put_error(lm, ft_array_free(&tmp, 30));
	(*lm)->mtx[from][to] = '+';
	(*lm)->mtx[to][from] = '+';
	(*lm)->con_c++;
	return (ft_array_free(&tmp, 30));
}

void			ft_lm_parse_input(t_lm **lm)
{
	char	*line;
	int		action;

	line = NULL;
	action = 10;
	while (f_get_next_line(0, &line) > 0)
	{
		ft_lst_push_back_data(&((*lm)->input), (void*)line);
		if (action == 10)
			action = ft_lm_add_ants(&line, lm);
		else if (action == 20 || action == 21 || action == 22)
			action = ft_lm_add_room(action, &line, lm);
		else if (action == 30)
			action = ft_lm_add_con(&line, lm);
	}
}
