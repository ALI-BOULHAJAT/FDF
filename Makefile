SRC = ./ft_alloc_read_mem/alloc_map.c ./ft_convert_to_int/ft_atoi.c ft_fdf.c \
	./ft_check_split/ft_split.c ./ft_check_split/ft_strchr.c ./ft_convert_to_int/pre_atoi.c ./ft_alloc_read_mem/map_to_mem.c \
	utils_fdf.c ./ft_check_split/check_color.c ./ft_convert_to_int/ft_hexanum.c ./ft_alloc_read_mem/get_next_line.c\

NAME = fdf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	gcc ft_fdf.c fdf.a -o fdf

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re


#gcc ./ft_convert_to_int/ft_atoi.c ft_fdf.c ./ft_check_split/ft_split.c ./ft_check_split/ft_strchr.c ./ft_convert_to_int/pre_atoi.c ./ft_alloc_read_print/print_map.c utils_fdf.c ./ft_check_split/check_color.c ./ft_convert_to_int/ft_hexanum.c ./ft_alloc_read_print/get_next_line/get_next_line.c ./ft_alloc_read_print/get_next_line/get_next_line_utils.c ./ft_alloc_read_print/alloc_map.c 