# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 16:11:43 by johmatos          #+#    #+#              #
#    Updated: 2023/06/25 11:05:51 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB	:= ./libft.a
MINISHELL_LIB := ./mini_libft.a
VPATH	:= ./src/io/ ./src/utils/ ./src/memory/ ./src/string/
BUILDDIR := objs/
MINISHELLDIR := mini_objs/
INCLUDE := /include
CC := cc
CFLAGS = -g -Wall -Werror -Wextra
SOURCES := ft_atoi.c ft_isalnum.c ft_isalpha.c \
		   ft_isascii.c ft_isdigit.c ft_isprint.c \
		   ft_ithex.c ft_itoa.c ft_ubase.c ft_split.c \
		   ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		   ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		   ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		   ft_substr.c ft_tolower.c ft_toupper.c ft_bzero.c \
		   ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		   ft_memmove.c ft_memset.c fmt_to_char.c fmt_to_decimal.c \
		   fmt_to_hex.c fmt_to_pointer.c fmt_to_string.c fmt_to_udecimal.c \
		   ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		   ft_putstr_fd.c get_next_line_bonus.c ft_safe_free.c \
		   get_next_line_utils_bonus.c parser.c \
		   ft_interpol.c ft_atoull.c ft_strcmp.c

MINISHELL_SRCS = ft_strlen.c ft_strdup.c ft_substr.c ft_itoa.c \
				 ft_split.c ft_strlcpy.c ft_isalpha.c \
				 ft_isalnum.c ft_putstr_fd.c ft_memmove.c ft_strncmp.c \
				 ft_strchr.c ft_bzero.c ft_strnstr.c ft_memset.c ft_isdigit.c \
				 ft_strjoin.c ft_atoull.c ft_atoi.c ft_memcpy.c ft_calloc.c \
				 ft_strlcat.c ft_strcmp.c ft_safe_free.c \
				 fmt_to_char.c fmt_to_decimal.c ft_putendl_fd.c \
				 fmt_to_hex.c fmt_to_pointer.c fmt_to_string.c fmt_to_udecimal.c ft_putchar_fd.c \
				 parser.c ft_ithex.c ft_ubase.c ft_toupper.c ft_printf.c

RCol='\033[0m'
Bla='\033[0;30m'
Red='\033[0;31m'
Gre='\033[1;32m'
Yel='\033[1;33m'
Blu='\033[0;34m'
Pur='\033[1;35m'
Cya='\033[0;36m'
Whi='\033[0;37m'

MSGBUILD="[$(Yel)+$(RCol)]"
ALTMSGBUILD="[$(Pur)+$(RCol)]"
MSGRM="[$(Red)-$(RCol)]"
OBJS := $(addprefix $(BUILDDIR), $(SOURCES:.c=.o))
MINISHELL_OBJS := $(addprefix $(MINISHELLDIR), $(MINISHELL_SRCS:.c=.o))

ifdef DEBUG
    CFLAGS += -g3
endif

all: $(LIB)

$(LIB): $(OBJS)
	@printf "\n";
	@ar -rcs $@ $?
	@printf "$(MSGBUILD) (libft): ok\n"

$(BUILDDIR)%.o: %.c
	@printf "$(MSGBUILD) (libft): building $@                        \r"
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	@$(CC) $(CFLAGS) -I./include -c $< -o $@

minishell: $(MINISHELL_LIB)

$(MINISHELL_LIB): $(MINISHELL_OBJS)
	ar -rcs $@ $?
	@printf "\n";
	@printf "$(ALTMSGBUILD) (libft): ok                              "

$(MINISHELLDIR)%.o: %.c
	@printf "$(MSGBUILD) (libft): building $@                        \r"
	@test -d $(MINISHELLDIR) || mkdir $(MINISHELLDIR)
	@$(CC) $(CFLAGS) -I./include -c $< -o $@

clean:
	@rm -rf $(BUILDDIR)
	@rm -rf $(MINISHELLDIR)

fclean: clean
	@rm -rf $(LIB)
	@rm -rf $(MINISHELL_LIB)
