NAME = so_long
SRC_GAME = code/main.c code/map.c code/game.c code/move.c code/flood_fill.c\
	code/animation.c code/check_element.c code/set_pos_player.c\

UTILS = code/utils/ft_strncmp.c code/utils/ft_putstr_fd.c code/utils/ft_strlen.c\
	code/utils/ft_itoa.c code/utils/ft_strjoin.c code/utils/ft_split.c\
	code/utils/get_next_line_utils.c code/utils/get_next_line.c code/utils/ft_strdup.c

SRC = $(SRC_GAME) $(UTILS)

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX = -Lminilibx-linux -lmlx -lXext -lX11
INCLUDE = -Iminilibx-linux -I .
all : ${NAME}

${NAME} : ${OBJ}
	make -C minilibx-linux
	${CC} ${CFLAGS} -I ./code ${SRC} -o ${NAME} ${MLX} ${INCLUDE}
clean :
	rm -rf $(OBJ)
	make clean -C minilibx-linux
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re code
