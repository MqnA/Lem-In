#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

typedef struct		s_line
{
	char			*remain;
	struct s_line	*next;
	int				fd;
}					t_line;

char				*read_line(int fd);
int					check_fd(int fd, t_line *begin_list);
t_line				*create_elem(int fd);
void				elem_add(int fd, t_line **begin_list);

#endif
