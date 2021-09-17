/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:45:52 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 20:28:37 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		room_find_by_name(t_lm *lm, char *name)
{
	int i;

	i = 0;
	while (lm->rooms[i])
	{
		if (ft_strcmp(lm->rooms[i]->name, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		room_find_by_i(t_lst *st, int i)
{
	while (st)
	{
		if (ROOM(st)->i == i)
			return (i);
		st = st->next;
	}
	return (-1);
}

t_room	*room_new(char **tmp)
{
	t_room	*new;
	int		cord_x;
	int		cord_y;

	cord_x = ft_atoi(tmp[1]);
	cord_y = ft_atoi(tmp[2]);
	if (ft_is_valid_int(cord_x, tmp[1]) == 0 ||
		ft_is_valid_int(cord_y, tmp[2]) == 0)
		return (NULL);
	if ((new = (t_room*)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	new->i = -1;
	new->vis = -1;
	new->bfs = -1;
	new->dist = -1;
	new->cord_x = cord_x;
	new->cord_y = cord_y;
	new->name = tmp[0];
	return (new);
}

t_room	*room_add_new(t_lm **lm, t_room *room)
{
	if ((*lm)->rooms_c >= MAX_ROOMS)
		put_error(lm, 1);
	room->i = (*lm)->rooms_c++;
	(*lm)->rooms[room->i] = room;
	return ((*lm)->rooms[room->i]);
}
