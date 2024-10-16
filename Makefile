# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bizcru <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 15:47:58 by bizcru            #+#    #+#              #
#    Updated: 2024/10/09 17:28:45 by bcanals-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnl.a

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=20

SRCS = get_next_line.c \
		get_next_line_utils.c

#BONUS_SRCS = ft_lstnew_bonus.c \

OBJS = $(SRCS:.c=.o)

#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) get_next_line.h Makefile
	ar rc $@ $(OBJS)
	ranlib $@ 

#bonus: $(NAME) $(BONUS_OBJS)
#	ar rcs $(NAME) $(BONUS_OBJS)

clean: 
	rm -f $(OBJS)

#bclean:
#	rm -f $(BONUS_OBJS)

fclean: clean #bclean
	rm -f getnl.a

re: fclean all

#################################
# TO BE DELETED BEFORE REVISION #
#################################

TEST = $(wildcard *test.c)

TESTNAME = test

TESTO = $(TEST:.c=.o)

test: $(TESTO) $(NAME)
	gcc $(CFLAGS) -c $(TEST)
	gcc $(TESTO) -o $(TESTNAME) getnl.a

cleant:
	rm -f $(TESTO)

retest: fclean cleant test
