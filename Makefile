BBLACK=\033[1;30m
BRED=\033[1;31m
BGREEN=\033[1;32m
BYELLOW=\033[1;33m
BBLUE=\033[1;34m
BPURPLE=\033[1;35m
BCYAN=\033[1;36m
BWHITE=\033[1;37m
RESET_COLOR=\033[0m

NAME = pipex
CC = cc
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
LIBFT_DPDS = $(wildcard $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h)

SRCS = parse.c \
	pipex.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT): $(LIBFT_DPDS)
		@make -C $(LIBFT_DIR)

%.o: %.c
		@echo -n "$(BGREEN)"
		$(CC) $(FLAGS) -I. -c $< -o $@
		@echo -n "$(RESET_COLOR)"

$(NAME): $(LIBFT) $(OBJS)
		@echo -n "$(BPURPLE)"
		$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
		@echo -n "$(RESET_COLOR)"

clean:
		@make clean -C $(LIBFT_DIR)
		@echo -n "$(BBLUE)"
		rm -f $(OBJS)
		@echo -n "$(RESET_COLOR)"

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@echo -n "$(BBLUE)"
		rm -f $(NAME)
		@echo -n "$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re
