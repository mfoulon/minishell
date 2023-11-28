NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm
RMFLAG = -f

ifeq ($(shell uname), Linux)
	PTHREAD_FLAGS = -pthread
endif

SRCS = \
	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PTHREAD_FLAGS)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean run fclean re 
