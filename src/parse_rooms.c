/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:52 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/10 14:27:08 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

static int ft_lm_coment_type(char **line)
{
	if ((*line)[0] && (*line)[0] == '#' && ft_strcmp((*line), "##start") == 0)
		return (21);
	else if ((*line)[0] && (*line)[0] == '#' && ft_strcmp((*line), "##end") == 0)
		return (22);
	else if ((*line)[0] && (*line)[0] == '#')
		return (20);
	return (0);
}

int ft_lm_add_room(int action, char **line, t_lm **lm)
{
	char **tmp;
	t_room	*new_room;

	if (ft_lm_coment_type(line) != 0)
		return (ft_lm_coment_type(line));
	if((action == 21 && (*lm)->room_start != NULL) ||
		(action == 22 && (*lm)->room_end != NULL))
		ft_lm_put_error(lm, ft_str_free(line, action));
	if ((tmp = ft_strsplit((*line), ' ')) == NULL)
		ft_lm_put_error(lm, ft_str_free(line, action));
	if (ft_array_len(tmp) != 3 || ft_lm_get_room_i(*lm, tmp[0]) != -1 ||
		(new_room = ft_lm_new_room(tmp)) == NULL)
		return (ft_lm_is_not_room(ft_array_free(&tmp, action), line, lm));
	ft_str_free(&(tmp[1]), ft_str_free(&(tmp[2]), action));
	free(tmp);
	if (action == 21)
		(*lm)->room_start = ft_lm_add_new_room(lm, new_room);
	else if (action == 22)
		(*lm)->room_end = ft_lm_add_new_room(lm, new_room);
	else
		ft_lm_add_new_room(lm, new_room);
	// printf("add room - %i\n", (*lm)->rooms_c);/////////TEST
	return (20);
}