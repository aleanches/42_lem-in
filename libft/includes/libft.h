/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:11:24 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:31:31 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include "f_get_next_line.h"

typedef struct			s_lst
{
	void				*data;
	struct s_lst		*next;
}						t_lst;

int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_islower(int ch);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_isupper(int ch);
int						ft_is_valid_int(int val_i, char *val_c);

char					*ft_itoa(int n);
char					*ft_ltoa(long int n);
char					*ft_lltoa(long long int n);
char					*ft_utoa(unsigned int n);
char					*ft_ultoa(unsigned long int n);
char					*ft_ulltoa(unsigned long long int n);
char					*ft_itoa_base(int val, int base);
char					*ft_lltoa_base(long long int val, int base);
char					*ft_ulltoa_base(unsigned long long int val, int base);

int						ft_atoi(const char *str);
int						ft_atoi_base(const char *str, int base);
unsigned long long int	ft_atoull_base(const char *str, int base);

t_lst					*ft_lst_new(void *data);
int						ft_lst_free(t_lst **lst,
						void (*free_data)(void **data), int ret_val);
void					ft_lst_iter(t_lst *lst, void (*f)(void *data));
t_lst					*ft_lst_pop_back(t_lst **lst);
t_lst					*ft_lst_pop_front(t_lst **lst);
void					ft_lst_push_back(t_lst **lst, t_lst *new);
void					ft_lst_push_front(t_lst **lst, t_lst *new);
void					*ft_lst_pop_back_data(t_lst **lst);
void					*ft_lst_pop_front_data(t_lst **lst);
t_lst					*ft_lst_push_back_data(t_lst **lst, void *data);
t_lst					*ft_lst_push_front_data(t_lst **lst, void *data);

void					***ft_mtx_new(unsigned int size,
						void *(*f)(unsigned x, unsigned y));
void					ft_mtx_free(void ****mtx, void (*f)(void **data));

void					ft_bzero(void *s, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst,
						const void *src, int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memrcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *buf, int ch, size_t count);
void					*ft_memdup(void *data, size_t size);

void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr(int n);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
int						ft_skipspace(const char *s);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t len);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char					*ft_strrchr(const char *s, int c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strsub(char const *s,
						unsigned int start, size_t len);
char					*ft_strtrim(char const *s);
int						ft_str_free(char **str, int ret_val);

int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_digitcount(long long int number);
size_t					ft_w_count(char const *s, char del);
int						ft_array_free(char ***array, int ret_val);
int						ft_array_len(char **array);
int						ft_sqrt(int nb);
double					ft_pow(double base, double exp);
long double				ft_powl(long double base, long double exp);
int						ft_abs(int nbr);
long int				ft_absl(long int n);

#endif
