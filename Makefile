
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address
NAME	=	minishell

SRC= built_in/ft_cd.c \
	built_in/ft_echo.c \
	built_in/ft_env.c \
	built_in/ft_exit.c \
	built_in/ft_export.c \
	built_in/ft_pwd.c \
	built_in/ft_unset.c \
	built_in/ft_utils.c \
	built_in/ft_export_utils.c \
	built_in/ft_export_utils2.c \
	built_in/ft_export_utils3.c \
	environment/env.c \
	executer/execute_exit_status.c \
	executer/execute_utils.c \
	executer/executer.c \
	executer/ft_execute.c \
	executer/execute_helpers.c \
	main.c \
	parser/cmdexe/cmdexe.c \
	parser/cmdexe/cmdexe_utils.c \
	parser/cmdexe/cmdexe_utils1.c \
	parser/concater/concater.c \
	parser/expander/expander_utils.c \
	parser/expander/expander_utils1.c \
	parser/expander/expander_utils2.c \
	parser/expander/expander_utils3.c \
	parser/expander/expander.c \
	parser/heredoce/here_doc.c \
	parser/heredoce/heredoc_utils.c \
	parser/cmdlist/cmdlist.c \
	parser/cmdlist/cmdlist_utils.c \
	signals/handle_signal.c \
	signals/utils.c \
	tokenizer/ft_rm_whitespace.c \
	tokenizer/syntax_checker.c \
	tokenizer/tokenizer.c\
	tokenizer/tokenizer_utils.c\
	tokenizer/tokenizer_utils2.c\
	tokenizer/tokenizer_utils3.c\
	manage_main/main_utils.c\
	manage_main/main_utils2.c\
	manage_main/list_to_array.c\

LIBFT=./libft/libft.a
OBJ=$(SRC:.c=.o)


RL_PATH=$(shell brew --prefix readline)

LIB = -L $(RL_PATH)/lib -lreadline 

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBFT)
	${CC} ${CFLAGS} $(LIB) ${LIBFT} ${OBJ} -o ${NAME} 

$(LIBFT):
	$(MAKE) all -C ./libft

%.o	:	%.c 
	$(CC)  $(CFLAGS) -I $(RL_PATH)/include  -c -o $@ $<

clean	:
	$(MAKE) clean -C ./libft 
	rm -f $(OBJ) 

fclean	:	clean 
	rm -f $(NAME) $(LIBFT)

re	: clean all

.PHONY: clean fclean re