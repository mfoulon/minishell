NAME = minishell

LIBFT		:= libft.a
LIBFT_PATH	:= "libft"

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

BUILTINS	=	srcs/builtins/env_builtin.c \
				srcs/builtins/export_builtin.c \
				srcs/builtins/cd_builtin.c \
				srcs/builtins/exit_builtin.c \
				srcs/builtins/pwd_builtin.c \
				srcs/builtins/echo_builtin.c \
				srcs/builtins/unset_builtin.c

CLEAR		=	srcs/clear/clean_minishell.c \
				srcs/clear/clear_parser.c \
				srcs/clear/garbage_collector.c

EXEC		=	srcs/exec/check.c \
				srcs/exec/exec_cmd.c \
				srcs/exec/exec_error.c \
				srcs/exec/exec_builtin.c \
				srcs/exec/exec.c \
				srcs/exec/redir.c

EXPAND		=	srcs/expand/asterisks.c \
				srcs/expand/expander_split.c \
				srcs/expand/expander_utils.c \
				srcs/expand/expander.c \
				srcs/expand/globber_utils.c \
				srcs/expand/globber.c \
				srcs/expand/expand_heredoc.c \
				srcs/expand/pre_expander.c \
				srcs/expand/quotes.c

INIT		=	srcs/init/env_utils.c \
				srcs/init/get_path.c \
				srcs/init/handle_heredoc.c \
				srcs/init/init_ast.c \
				srcs/init/init_envlst.c \
				srcs/init/signal.c

PARSING		=	srcs/parsing/append_cmd.c \
				srcs/parsing/nodes.c \
				srcs/parsing/parse_error.c \
				srcs/parsing/parse_utils.c \
				srcs/parsing/parser.c

TOKEN		=	srcs/tokenization/token_lst.c \
				srcs/tokenization/token_utils.c \
				srcs/tokenization/tokenization_appender.c \
				srcs/tokenization/tokenize.c

SRCS			=	$(BUILTINS) \
					$(CLEAR) \
					$(EXEC) \
					$(EXPAND) \
					$(INIT) \
					$(PARSING) \
					$(TOKEN) \
					main.c

OBJS		:=	$(SRCS:.c=.o)

READLINE_PATH:=	/goinfre/homebrew/opt/readline

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -Iincludes -I$(READLINE_PATH)/include
		
all:	$(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
		@$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
