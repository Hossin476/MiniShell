# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykhourba <ykhourba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 12:22:48 by ykhourba          #+#    #+#              #
#    Updated: 2023/05/26 14:16:48 by ykhourba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g	
NAME	=	libft.a
OBJ		=	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
			ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o \
			ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
			ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o \
			ft_tolower.o ft_toupper.o ft_strcmp.o
OBJ_B	=	ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstlast.o ft_lstnew.o ft_lstsize.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o
LIBFT_H	=	libft.h
AR		=	ar rcs
all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) $(OBJ)

bonus	:	$(OBJ_B)
		$(AR) $(NAME) $(OBJ_B)

%.o	:	%.c $(LIBFT_H)
	$(CC)  $(CFLAGS) -c -o $@ $<

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean	:	clean 
	rm -f $(NAME)

re	:	clean all bonus