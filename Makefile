
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
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

HELPERS = 	./helpers/ft_atoi.c \
			./helpers/ft_isalnum.c \
			./helpers/ft_isalpha.c \
			./helpers/ft_isdigit.c \
			./helpers/ft_itoa.c \
			./helpers/ft_memcpy.c \
			./helpers/ft_putstr_fd.c \
			./helpers/ft_putchar_fd.c \
			./helpers/ft_putendl_fd.c \
			./helpers/ft_split.c \
			./helpers/ft_strchr.c \
			./helpers/ft_strcmp.c \
			./helpers/ft_strdup.c \
			./helpers/ft_strjoin.c \
			./helpers/ft_strlen.c \
			./helpers/ft_strncmp.c \
			./helpers/ft_strnstr.c \
			./helpers/ft_strrchr.c \
			./helpers/ft_strtrim.c \
			./helpers/ft_substr.c \

OBJ=$(SRC:.c=.o)
OBG_H = $(HELPERS:.c=.o)
INCLUDE_DIR = include
ABS_PATH = 	$(INCLUDE_DIR)/minishell.h $(INCLUDE_DIR)/builtin.h \
			$(INCLUDE_DIR)/cmdexe.h $(INCLUDE_DIR)/cmdlist.h \
			$(INCLUDE_DIR)/concater.h $(INCLUDE_DIR)/env.h \
			$(INCLUDE_DIR)/executer.h $(INCLUDE_DIR)/expander.h\
			$(INCLUDE_DIR)/helpers.h $(INCLUDE_DIR)/here_doc.h\
			$(INCLUDE_DIR)/tokenizer.h

RL_PATH=$(shell brew --prefix readline)

LIB = -L $(RL_PATH)/lib -lreadline 

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(OBG_H)
	${CC} ${CFLAGS} $(LIB) ${OBG_H} ${OBJ} -o ${NAME} 


%.o	:	%.c  $(ABS_PATH)
	$(CC)  $(CFLAGS) -I $(INCLUDE_DIR) -I $(RL_PATH)/include -c $< -o $@

clean	: 
	rm -f $(OBJ) $(OBG_H)

fclean	:	clean 
	rm -f $(NAME)

re	: clean all

.PHONY: clean fclean re