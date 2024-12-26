# **************************************************************************** #
# CONFIG                                                                       #
# **************************************************************************** #
NAME		=	so_long

# Compiler and flags
CC			=	@cc
RM			=	@rm -f
CCFLAGS		=	-Wall -Werror -Wextra -Iinclude/mlx
MLXFLAGS	=	-L/usr/X11/lib -lX11 -lXext -Llibs/mlx_linux -lm

# Directories and source files
SRCS_DIR    =   src
LIBS_DIR	=	includes
SRCS        =   $(SRCS_DIR)/error.c \
                $(SRCS_DIR)/graphics.c \
                $(SRCS_DIR)/movement.c \
                $(SRCS_DIR)/parse.c \
                $(SRCS_DIR)/so_long.c

OBJS		=	$(SRCS:.c=.o)

# Libraries
LIBS		=	$(LIBS_DIR)/Libft/libft.a \
				$(LIBS_DIR)/get_next_line/gnl.a \
				$(LIBS_DIR)/ft_printf/libftprintf.a \
				minilibx-linux/libmlx.a

# **************************************************************************** #
# COLOURS                                                                      #
# **************************************************************************** #
BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;33m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

# Messages
SUCCESS		=	@echo "$(YELLOW)so_long compiled successfully$(COLOR)"
S_OBJS		=	@echo "$(BLUE)cleaning of objects completed <(￣︶￣)>$(COLOR)"
S_NAME		=	@echo "$(CYAN)full clean completed ! ヽ(・∀・)ﾉ$(COLOR)"

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #
all:		$(NAME)

$(NAME):	$(OBJS)
			@make -sC $(LIBS_DIR)/Libft
			@make -sC $(LIBS_DIR)/ft_printf
			@make -sC $(LIBS_DIR)/get_next_line
			@make --no-print-directory -sC minilibx-linux
			$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(MLXFLAGS)
			$(SUCCESS)

clean:
			$(RM) $(OBJS)
			@make --no-print-directory -sC $(LIBS_DIR)/Libft clean
			@make --no-print-directory -sC $(LIBS_DIR)/ft_printf clean
			@make --no-print-directory -sC $(LIBS_DIR)/get_next_line clean
			@make --no-print-directory -sC minilibx-linux clean
			$(S_OBJS)

fclean:		clean
			$(RM) $(NAME)
			@make --no-print-directory -sC $(LIBS_DIR)/Libft fclean
			@make --no-print-directory -sC $(LIBS_DIR)/ft_printf fclean
			@make --no-print-directory -sC $(LIBS_DIR)/get_next_line fclean
			$(RM) minilibx-linux/libmlx.a
			$(S_NAME)

re:			fclean all

# **************************************************************************** #
# PHONY                                                                        #
# **************************************************************************** #
.PHONY:		all clean fclean re