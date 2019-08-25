/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_next_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 02:05:50 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/25 19:29:46 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_GET_NEXT_LINE_H
# define F_GET_NEXT_LINE_H
# include "libft.h"
# define CONT (*gnl->cur_fd)->buf->content
# define SIZE (*gnl->cur_fd)->buf->content_size
# define F_BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fd
{
	t_list			*buf;
	int				fd;
}					t_fd;

typedef struct		s_gnl
{
	char			buf[F_BUFF_SIZE];
	t_list			*fd_lst;
	t_fd			**cur_fd;
	ssize_t			ret;
	ssize_t			read_ret;
	ssize_t			lst_ofset;
	ssize_t			node_ofset;
	int				fd;
	char			*tmp_ptr;
}					t_gnl;

ssize_t				f_get_next_line(const int fd, char **line);
void				clear_fd_node(t_gnl *gnl);
void				fd_lst_clear(void *content, size_t size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstclear(void *content, size_t size);
void				ft_lstclear(void *content, size_t size);
size_t				ft_lstcount(t_list *lst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelnode(t_list **lst, t_list *node);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstpushback(t_list **alst, t_list *new);

#endif
