NAME = cub3d

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
INC_DIR		=	includes
SRC_DIR		=	$(shell find srcs -type d)
LIB_DIR		=	-Llibrairie/minilibx-linux -lm -lmlx -lXext -lX11

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRCS		=	main.c					\
				print.c					\
				free.c					\
				get_next_line.c			\
				get_next_line_utils.c	\
				check_map.c				\
				init_map.c				\
				alloc.c					\
				lst_utils.c				\
				str_utils.c

OBJS		=	$(SRCS:%.c=${OBJ_DIR}/%.o)

RM			= rm -rf

CC			=	clang
CFLAGS		=	-Werror -Wall -Wextra -g3

NORM = norminette srcs includes

all:	${NAME}

$(NAME):	${OBJS} $(INC_DIR)/cub3d.h
		${CC} ${CFLAGS} ${OBJS} -I ${INC_DIR} -o ${NAME}
	@echo "$(GREEN)##### cub3d compiling finished! #####$(DEFAULT)"

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub3d.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	mkdir -p $@

norm : @$(NORM)

clean:
		${RM} $(OBJ_DIR)

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re norm
