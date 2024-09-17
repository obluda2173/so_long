SRCS		=	$(wildcard src/*.c)

LIBS		=	get_next_line/gnl.a Libft/libft.a ft_printf/libftprintf.a minilibx/libmlx.a

OBJS		=	$(SRCS:.c=.o)

CC			=	@cc
RM			=	@rm -f
CCFLAGS		=	-Wall -Werror -Wextra -Iinclude/mlx
MLXFLAGS	=	-framework OpenGL -framework Appkit

BLUE		=	\033[0;94m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;33m
CYAN		=	\033[0;96m
COLOR		=	\033[0m

SUCCESS		=	@echo "$(YELLOW)so_long compiled successfully$(COLOR)"
S_OBJS		=	@echo "$(BLUE)cleaning of objects completed <(￣︶￣)>$(COLOR)"
S_NAME		=	@echo "$(CYAN)full clean completed ! ヽ(・∀・)ﾉ$(COLOR)"

NAME		=	so_long

%.o:		%.c
			$(CC) $(CCFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -sC libft
			@make -sC ft_printf
			@make -sC get_next_line
			@make -sC minilibx
			$(CC) $(CCFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)
			$(SUCCESS)

clean:
			$(RM) $(OBJS)
			@make --no-print-directory -sC Libft clean
			@make --no-print-directory -sC ft_printf clean
			@make --no-print-directory -sC get_next_line clean
			@make --no-print-directory -sC minilibx clean
			$(S_OBJS)

fclean:		clean
			$(RM) $(NAME)
			@make --no-print-directory -sC Libft fclean
			@make --no-print-directory -sC ft_printf fclean
			@make --no-print-directory -sC get_next_line fclean
			@make --no-print-directory -sC minilibx fclean
			$(S_NAME)

re:			fclean all

.PHONY:		all clean fclean re