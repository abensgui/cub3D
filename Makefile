CC = cc 

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SRCS =	parsing/ft_map.c\
		parsing/get_next_line.c\
		parsing/get_next_line_utils.c\
		parsing/ft_split1.c\
		parsing/ft_isdigit.c\
		parsing/ft_color.c\
		parsing/ft_joinchar.c\
		parsing/check_element.c\
		parsing/check_map.c\
		parsing/check_data.c\
		parsing/open_fille.c\
		parsing/print_error.c\
		parsing/ft_wall.c\
		parsing/ft_catstr.c\
		parsing/ft_ins.c\
		parsing/skip_space.c\
		parsing/line_space.c\
		ray_casting/mainCub.c \
		ray_casting/ft_event.c \
		ray_casting/ft_mlx.c \
		ray_casting/ft_set_player.c \
		ray_casting/ft_init_map.c \
		ray_casting/ft_readmap.c \
		ray_casting/ft_split.c \
		ray_casting/ft_key_moves.c \
		ray_casting/ray_casting.c \
		ray_casting/check_file_name.c \
		ray_casting/is_far_from_wall.c \
		ray_casting/is_far_from_wall_util.c \
		ray_casting/player_view.c \
		ray_casting/put_texture.c \
		ray_casting/texture_walls.c \
		ray_casting/rgb_convert.c 


OBJS = ${SRCS:.c=.o}

NAME = cub3d

REM = rm -f

all : $(NAME) 

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	${REM} ${OBJS}

fclean : clean
	${REM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
