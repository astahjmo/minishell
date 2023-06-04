NAME = minishell
VPATH= ./src \
./src/parser ./src/prompt ./src/signals \
 ./src/here_doc ./src/utils \
 ./src/handler_quotes \
 ./src/tokenizer \
 ./src/syntax ./src/env ./src
CC = gcc
CFLAGS = -g -std=gnu18 -Wall -Wextra -Werror
SOURCES = main.c wait_input.c tokenizer.c setup_hook.c\
		  heredoc.c check_unclosed.c display.c \
		  init_signal.c clear_bimatrix.c \
		  find_token.c strings_utils.c\
		  tokenizer_operator.c init_parsers.c linked_list.c \
		  tokenizer_string.c analysis.c free_cmds.c recipeWord.c \
		  recipeOperator.c init_recipes.c lexer_strings.c init_hash.c \
		  hash_function.c env_linked_list.c \
		  env_utils.c ft_strjoinfree.c
		

BUILDDIR = ./build/
LINCLUDE= ./lib/include
INCLUDE = ./include
LIB = libft.a
OBJS = $(addprefix $(BUILDDIR), $(SOURCES:.c=.o))

RCol='\e[0m'
Bla='\e[0;30m'
Red='\e[0;31m'
Gre='\e[0;32m'
el='\e[0;33m'
Blu='\e[0;34m'
Pur='\e[0;35m'
Cya='\e[0;36m'
Whi='\e[0;37m'

MSGBUILD="[$(el)+$(RCol)]"
MSGRM="[$(Pur)-$(RCol)]"

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "$(MSGBUILD) Building: $(LIB)"
	@make --no-print-directory -C ./lib
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -Llib -lft -lreadline -o $@
	@echo "$(MSGBUILD) program $@ has created"

$(BUILDDIR)%.o: %.c
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LINCLUDE) -c $< -o $@
	@echo "$(MSGBUILD) Building: $@"

clean:
	@echo "$(MSGRM) removing $(BUILDDIR) dir "
	@make --no-print-directory -C ./lib clean
	@rm -rf $(BUILDDIR)

fclean: clean
	@echo "$(MSGRM) removing $(BUILDDIR) dir and $(NAME) bin"
	@make --no-print-directory -C ./lib fclean
	@if test -f $(NAME); then rm -f $(NAME); fi

re: fclean all
