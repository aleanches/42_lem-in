/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:46:29 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/13 20:35:43 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem-in.h"

int ft_lm_get_room_i(t_lm *lm, char *name)
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

t_room	*ft_lm_new_room(char **tmp)
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
	new->x = 0;
	new->vis = -1;
	new->dist = -1;
	new->cord_x = cord_x;
	new->cord_y = cord_y;
	new->name = tmp[0];
	return (new);
}

void 	ft_lm_set_def_rooms_val(t_lm *lm)
{
	int i;

	i = 0;
	while (lm->rooms[i])
	{
		lm->rooms[i]->dist = -1;
		lm->rooms[i]->vis = -1;
		i++;
	}
}

t_room	*ft_lm_add_new_room(t_lm **lm, t_room *room)
{
	if ((*lm)->rooms_c >= MAX_ROOMS)
		ft_lm_put_error(lm, 1);
	return ((*lm)->rooms[room->i = (*lm)->rooms_c++] = room);
}
