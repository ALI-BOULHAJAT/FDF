SRCS = ./fdf_M/ft_alloc_read_mem/alloc_map.c ./fdf_M/ft_convert_to_int/ft_atoi.c ./fdf_M/utils_fdf.c \
	./fdf_M/ft_check_split/ft_split.c ./fdf_M/ft_check_split/ft_strchr.c ./fdf_M/ft_convert_to_int/pre_atoi.c ./fdf_M/ft_alloc_read_mem/map_to_mem.c \
	./fdf_M/ft_check_split/check_color.c ./fdf_M/ft_convert_to_int/ft_hexanum.c ./fdf_M/ft_alloc_read_mem/get_next_line.c ./fdf_M/draw.c \
	./fdf_M/error.c ./fdf_M/utils2_fdf.c \

BONUS_SRCS = ./fdf_bonus/ft_alloc_read_mem/alloc_map.c ./fdf_bonus/ft_convert_to_int/ft_atoi.c ./fdf_bonus/utils_fdf_bonus.c \
	./fdf_bonus/ft_check_split/ft_split.c ./fdf_bonus/ft_check_split/ft_strchr.c ./fdf_bonus/ft_convert_to_int/pre_atoi.c ./fdf_bonus/ft_alloc_read_mem/map_to_mem.c \
	./fdf_bonus/ft_check_split/check_color.c ./fdf_bonus/ft_convert_to_int/ft_hexanum.c ./fdf_bonus/ft_alloc_read_mem/get_next_line.c ./fdf_bonus/draw_bonus.c \
	./fdf_bonus/error_bonus.c ./fdf_bonus/utils2_fdf_bonus.c ./fdf_bonus/fdf_bonus.c ./fdf_bonus/movement_func_bonus.c ./fdf_bonus/utils_bonus.c ./fdf_bonus/mouse_func_bonus.c ./fdf_bonus/ft_rotation.c 

NAME = fdf.a

CC = gcc

CFLAGS = -I.

OBJECT = $(SRCS:.c=.o)
BONUS_OBJECT = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	gcc -g ./fdf_M/fdf_M.c ./fdf.a -lmlx -framework OpenGL -framework AppKit -o fdf

bonus : $(BONUS_OBJECT)
	rm -f $(OBJECT) $(NAME)
	ar rc $(NAME) $(BONUS_OBJECT)
	gcc -g ./fdf_bonus/fdf_bonus.c ./fdf.a -lmlx -framework OpenGL -framework AppKit -o fdf

clean :
	rm -f $(OBJECT) $(BONUS_OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re