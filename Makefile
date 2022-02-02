SRC = ./ft_alloc_read_mem/alloc_map.c ./ft_convert_to_int/ft_atoi.c ft_fdf.c \
	./ft_check_split/ft_split.c ./ft_check_split/ft_strchr.c ./ft_convert_to_int/pre_atoi.c ./ft_alloc_read_mem/map_to_mem.c \
	utils_fdf.c ./ft_check_split/check_color.c ./ft_convert_to_int/ft_hexanum.c ./ft_alloc_read_mem/get_next_line.c draw.c\

NAME = fdf.a

CC = gcc

CFLAGS = -I.

OBJECT = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
#	make -C ./minilibx_macos/
	ar rc $(NAME) $(OBJECT)
	gcc -g ft_fdf.c fdf.a -lmlx -framework OpenGL -framework AppKit -o fdf

clean :
	rm -f $(OBJECT)
#	make clean -C ./minilibx_macos/

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re


#gcc ./ft_convert_to_int/ft_atoi.c ft_fdf.c ./ft_check_split/ft_split.c ./ft_check_split/ft_strchr.c ./ft_convert_to_int/pre_atoi.c ./ft_alloc_read_mem/map_to_mem.c utils_fdf.c ./ft_check_split/check_color.c ./ft_convert_to_int/ft_hexanum.c ./ft_alloc_read_mem/get_next_line.c ./ft_alloc_read_mem/alloc_map.c draw.c


# -framework OpenGL -framework AppKit

# make -f Makefile.mk -C ./minilibx/
# ./minilibx/configure
# ./minilibx/libmlx.a