NAME = cub3d

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
INC_DIR		=	includes
SRC_DIR		=	$(shell find srcs -type d)
LIB_DIR		=	-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LIB		=	./mlx/libmlx_Linux.a
MLX			=	./mlx

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRCS		=	main.c					\
				error_msg.c				\
				free_mlx.c				\
				free.c					\
				raycasting.c			\
				render.c				\
				get_next_line.c			\
				get_next_line_utils.c	\
				init_mlx.c				\
				init_map.c				\
				init_rgb.c				\
				init_to_null.c			\
				init_txturs.c			\
				keypress.c				\
				check_ext.c				\
				check_map.c				\
				check_txturs.c			\
				data_map.c				\
				parsing_map.c			\
				alloc.c					\
				lst_utils.c				\
				split.c					\
				str_utils.c				\
				utils.c

OBJS		=	$(SRCS:%.c=${OBJ_DIR}/%.o)

.c.o:
		${CC} ${CFLAGS} -I${MLX} -g3 -c $< -o ${<:.c=.o}

RM			= rm -rf

CC			=	clang
CFLAGS		=	-Werror -Wall -Wextra -g3

all:	${NAME}

${MLX_LIB}:
		make -C ${MLX} -j

$(NAME):	${MLX_LIB} ${OBJS} $(INC_DIR)/cub3d.h
		${CC} ${CFLAGS} ${OBJS} -I ${INC_DIR} -o ${NAME} ${MLX_LIB} ${LIB_DIR}
		@echo "$(GREEN)##### cub3d compiling finished! #####$(DEFAULT)"

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub3d.h | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
		mkdir -p $@

clean:
		${RM} $(OBJ_DIR)
		make clean -C ${MLX}
fclean:		clean
		${RM} ${NAME}
		${RM} ${MLX_LIB}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re norm
