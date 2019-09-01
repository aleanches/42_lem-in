/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:05:30 by vsanta            #+#    #+#             */
/*   Updated: 2019/09/01 13:29:49 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "libft.h"

# define MAX_ROOMS 15000
# define MAX_ROUTE_LEN 100
# define MAX_ROUTES_C 15
# define ROOM(R) ((t_room*)(R->data))
# define ROUTE(R) ((t_route*)R->data)

typedef struct		s_ant
{
	int				ant_n;
	t_lst			*room_cur;
}					t_ant;

typedef struct		s_room
{
	int				i;
	int				vis;
	int				bfs;
	int				dist;
	int				cord_x;
	int				cord_y;
	char			*name;
}					t_room;

typedef struct		s_route
{
	int				len;
	int				ants;
	t_lst			*rooms;
}					t_route;

typedef struct		s_lm
{
	int				ants_c;
	int				rooms_c;
	int				con_c;
	t_ant			**ants;
	t_room			*rooms[MAX_ROOMS + 1];
	t_room			*room_start;
	t_room			*room_end;
	char			**mtx;
	t_lst			*routes_a;
	t_lst			*routes_b;
	t_lst			*input;
}					t_lm;

t_ant				**ft_lm_ants_new(t_lm **lm);
int					ft_lm_ants_calc_on_routs(t_lm *lm, t_lst *routes);
void				ft_lm_ants_run(t_lm *lm, t_lst *routes);
int					ft_lm_bfs(t_lm *lm, int no_vis, t_room *start, t_room *end);
char				**ft_lm_mtx_new(int size, char def_val);
int					ft_lm_coment_type(char **line);
int					ft_lm_is_not_room(int action, char **line, t_lm **lm);
void				ft_lm_parse_input(t_lm **lm);
int					ft_lm_add_con(char **line, t_lm **lm);
int					ft_lm_room_find_by_name(t_lm *lm, char *name);
int					ft_lm_room_find_by_i(t_lst *st, int i);
t_room				*ft_lm_room_new(char **tmp);
t_room				*ft_lm_room_add_new(t_lm **lm, t_room *room);
void				ft_lm_set_def(t_lm *lm, int vis, int bfs, int dist);
void				ft_lm_route_s_e_set(t_lm *lm, t_lst *rooms, char c);
void				ft_lm_routes_s_e_open(t_lm *lm, t_lst *routes);
void				ft_lm_close_cross(t_lm *lm);
int					ft_lm_routes_set(t_lm *lm);
void				ft_lm_put_error(t_lm **lm, int ret_val);
void				ft_lm_free_rooms(t_room **rooms);
void				ft_lm_free_ants(t_ant **ants);
int					ft_lm_free_route(t_lst **route, int ret_val);
int					ft_lm_free_routes(t_lst **routes, int ret_val);
int					ft_lm_free_input(t_lst **input, int ret_val);

#endif
