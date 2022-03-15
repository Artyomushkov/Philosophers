NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -g -pthread -c $< -o $@

SRCS =	main.c \
		monitor.c \
		philosophers1.c \
		initialisation.c \
		time.c \
		utils.c \
		changed_atoi.c \

HEADER = philo.h

OBJS = $(SRCS:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(OBJS):	$(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -pthread -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all