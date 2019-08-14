/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem-in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:05:30 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/14 17:09:42 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft.h"

# define MAX_ROOMS 15000
# define ROOM(R) ((t_room*)(R->data))

typedef struct		s_room
{
	int				i;
	int				vis;
	int				dist;
	int				cord_x;
	int				cord_y;
	char			*name;
}					t_room;

typedef struct		s_route
{
	int				len;
	t_lst			*rooms;
}					t_route;

typedef struct		s_lm
{
	int				ants_c;
	int				rooms_c;
	t_room			*rooms[MAX_ROOMS + 1];
	t_room			*room_start;
	t_room			*room_end;
	t_lst			*routes;
	char			**mtx;
}					t_lm;

void	ft_lm_put_error(t_lm **lm, int ret_val);
int ft_lm_set_count_ants(char **line, t_lm **lm);
int ft_lm_add_con(char **line, t_lm **lm);
int ft_lm_add_room(int action, char **line, t_lm **lm);
void	ft_lm_parse_input(t_lm **lm);
int	ft_lm_is_not_room(int action, char **line, t_lm **lm);
char **ft_lm_mtx_new(int size, char def_val);
int ft_lm_get_room_i(t_lm *lm, char *name);
void print_lm(t_lm *lm);
int	ft_lm_free(t_lm **lm, int ret_val);
t_room	*ft_lm_new_room(char **tmp);
t_room	*ft_lm_add_new_room(t_lm **lm, t_room *room);
int		ft_lm_bfs(t_lm *lm, t_room *start);
t_route		*ft_lm_get_route(t_lm **lm, t_room *start, t_room *end);
void	print_route(void *data);
void 	ft_lm_set_route_s_e(t_lm *lm, t_lst *route, char c);
void 	ft_lm_close_cross(t_lm *lm);
void 	ft_lm_close_route_all(t_lm *lm, t_lst *route);
void 	ft_lm_open_routes_s_e(t_lm *lm, t_lst *routes);
void 	ft_lm_set_route_s_e(t_lm *lm, t_lst *route, char c);
t_route		*ft_lm_get_route(t_lm **lm, t_room *start, t_room *end);
t_lst 	*ft_lm_get_routes_sr(t_lm **lm);



#endif
