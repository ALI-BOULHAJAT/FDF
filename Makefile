SRC = alloc_map.c ft_atoi.c ft_fdf.c ft_split.c ft_strchr.c \
	get_next_line.c pre_atoi.c print_col_map.c print_map.c \
	utils_fdf.c check_color.c \
	ft_hexanum.c 

NAME = fdf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT)

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re