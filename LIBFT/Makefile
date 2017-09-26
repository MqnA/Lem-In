# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavagner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 15:26:03 by mavagner          #+#    #+#              #
#    Updated: 2017/04/19 16:05:23 by mavagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CCFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = is_digit.c \
	  sort/bubble_sort.c \
	  sort/selection_sort.c \
	  sort/quick_sort.c \
	  sort/heap_sort.c \
	  sort/insertion_sort.c \
	  ft_printf/ft_printf.c \
	  ft_printf/ft_printf_c.c \
	  ft_printf/ft_printf_cast_lmod.c \
	  ft_printf/ft_printf_check_conv.c \
	  ft_printf/ft_printf_dioux.c \
	  ft_printf/ft_printf_init.c \
	  ft_printf/ft_printf_itoa.c \
	  ft_printf/ft_printf_itoa_base.c \
	  ft_printf/ft_printf_p.c \
	  ft_printf/ft_printf_percent.c \
	  ft_printf/ft_printf_s.c \
	  ft_joinfree.c \
	  free2d.c \
	  ft_display.c \
	  ft_putnstr.c \
	  ft_strtoupper.c \
	  ft_uitoa_base.c \
	  ft_uitoa.c \
	  get_next_line/get_next_line.c \
	  get_next_line/list_opereations.c \
	  ft_strsub_free.c \
	  ft_strjoin_free.c \
	  ft_lstmap.c \
	  ft_lstiter.c \
	  ft_lstadd.c \
	  ft_lstpush.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstnew.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_swap.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all : $(NAME)

norme:
	norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

list:
	@echo $(OBJ)

re: fclean all

.PHONY: all clean fclean re
