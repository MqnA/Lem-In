NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LEM_IN_SRC =  srcs/main.c \
			  srcs/ft_error.c \
			  srcs/solve.c \
			  srcs/links_tab.c \
			  srcs/init.c \
			  srcs/free.c \
			  srcs/get_ants.c \
			  srcs/add_room.c \
			  srcs/add_path.c \
			  srcs/check_room.c \
			  srcs/check_map.c \
			  srcs/print.c \
			  srcs/lem_in.c \

OBJ = $(LEM_IN_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C LIBFT/
	$(CC) $(CFLAGS) $(LEM_IN_SRC) LIBFT/libft.a -o $(NAME)
	@printf "LEMIN IS READY !!! \n"

clean:
	rm -rf $(OBJ)
	make -C LIBFT clean

fclean: clean
	rm -rf $(NAME)
	make -C LIBFT fclean

re: fclean all

.PHONY: all clean fclean re
