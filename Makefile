NAME = so_long
SRC_GAME = src/main.c src/map.c src/game.c src/move.c src/flood_fill.c\
	src/animation.c src/check_element.c src/set_pos_player.c\

UTILS = src/utils/ft_strncmp.c src/utils/ft_putstr_fd.c src/utils/ft_strlen.c\
	src/utils/ft_itoa.c src/utils/ft_strjoin.c src/utils/ft_split.c\
	src/utils/get_next_line_utils.c src/utils/get_next_line.c src/utils/ft_strdup.c

SRC = $(SRC_GAME) $(UTILS)

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX = -Lminilibx-linux -lmlx -lXext -lX11
INCLUDE = -Iminilibx-linux -I .
all : ${NAME}

${NAME} : ${OBJ}
	make -C minilibx-linux
	${CC} ${CFLAGS} -I ./src ${SRC} -o ${NAME} ${MLX} ${INCLUDE}
clean :
	rm -rf $(OBJ)
	make clean -C minilibx-linux
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re src
