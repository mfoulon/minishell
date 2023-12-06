NAME = minishell

LIBFT		:= libft.a
LIBFT_PATH	:= "libft"

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

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) $(PTHREAD_FLAGS)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean run fclean re 
