# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 23:25:46 by piyu              #+#    #+#              #
#    Updated: 2024/11/19 02:51:17 by piyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putend1_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

%.o: %.c
	@$(COMPILER) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(OBJS) $(BONUS_OBJS)
		@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
		touch .bonus

clean:
		@rm -f $(OBJS) $(BONUS_OBJS)

fclean:	clean
		@rm -f $(NAME)
		@rm -f .bonus

re:		fclean all

.PHONY:	all clean fclean re bonus
