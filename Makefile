NAME = cub3d

GREEN		=	\033[1;32m
RED			=	\033[1;31m
DEFAULT		=	\033[0m

OBJ_DIR		=	objs
INC_DIR		=	include
SRC_DIR		=	$(shell find srcs -type d)
LIB_DIR		=	-Llibrairie/minilibx-linux -lm -lmlx -lXext -lX11

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRCS		=	main.c	\

OBJS		=	$(SRCS:%.c=${OBJ_DIR}/%.o)

RM			= /usr/bin/rm

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
		${RM} -r $(OBJ_DIR)

fclean:		clean
		${RM} ${NAME}

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re norm
