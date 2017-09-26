/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:39:28 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:22:28 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FLAGS "#- +0"
# define L_MOD "hljz"
# define MY_FD (*cpy)->my_fd
# define CPY (*cpy)->content
# define IF_LINE (*cpy)->if_line
# define BUFF_SIZE 1000

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

typedef enum		e_del
{
	FIRST,
	SECOND,
	BOTH
}					t_del;

typedef struct		s_data
{
	int				neg;
	int				pos;
	int				zero;
	int				sharp;
	int				prec;
	int				prec_ok;
	int				space;
	int				width_min;
	int				ret;
	enum
	{
		none,
		l,
		ll,
		h,
		hh,
		j,
		z
	}				l_mod;
}					t_data;

typedef struct		s_next
{
	char			*content;
	int				my_fd;
	int				if_line;
	struct s_next	*next;
}					t_content;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					is_digit(char *line);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isconv(char c);
int					ft_isconv2(char c);
int					ft_atoi(const char *str);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					ft_printf_itoa(intmax_t n, t_data *flag);
int					ft_printf_itoa_base(uintmax_t n, int base,
					t_data *flag, char c);
int					ft_printf_p(unsigned long n, t_data *flag);
int					ft_printf_c(char c, t_data *flag);
int					ft_printf_s(char *str, t_data *flag);
int					ft_printf_dioux(va_list av, char c, t_data *flag);
int					ft_printf_percent(t_data *flag);
int					ft_check_conv(va_list av, char c, t_data *flag);
int					ft_display(char **format, va_list av);
void				ft_init_struct(t_data *flag);
void				ft_init_enum(char **format, t_data *flag);
void				ft_init_prec(char **format, t_data *flag);
void				ft_init_width(char **format, t_data *flag);
void				ft_init_flag(char **format, t_data *flag);
intmax_t			ft_cast_lmod_di(va_list av, t_data *flag);
uintmax_t			ft_cast_lmod_oux(va_list av, t_data *flag);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *str);
void				bubble_sort(int *arr, int n);
void				heap_sort(int *arr, int n);
void				selection_sort(int *arr, int n);
void				insertion_sort(int *arr, int n);
void				quick_sort(int *arr, int low, int high);
void				ft_swap(int *a, int *b);
void				ft_lstpush(t_list **head, void const *content,
								int content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_putendl(const char *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnstr(char *str, int len);
void				ft_putstr(const char *str);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				free_2d(char **lines);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strsub_free(char *s, unsigned int start, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strnew(size_t size);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int c);
char				*ft_strtoupper(char *str);
char				*ft_joinfree(char *str1, char *str2, t_del string);

#endif
