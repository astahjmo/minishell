NAME  = minishell
VPATH = ./src \
		./src/parser ./src/prompt ./src/signals \
 		./src/here_doc ./src/utils \
 		./src/handler_quotes \
 		./src/tokenizer \
 		./src/syntax ./src/env ./src \
		./src/builtins ./src/executor
CFLAGS = -g -std=gnu18 -Wall -Wextra -Werror
SOURCES = main.c wait_input.c tokenizer.c setup_hook.c\
		  heredoc.c check_unclosed.c display.c \
		  init_signal.c clear_bimatrix.c \
		  find_token.c strings_utils.c\
		  tokenizer_operator.c init_parsers.c linked_list.c \
		  tokenizer_string.c analysis.c free_cmds.c recipeWord.c \
		  recipeOperator.c init_recipes.c lexer_strings.c \
		  ft_strjoinfree.c \
		  env_cmd.c exit_cmd.c executor.c \
		  init_env.c init_statics.c \
	

BUILDDIR = ./build/
LINCLUDE= ./lib/include
INCLUDE = ./include
LIB = libft.a
OBJS = $(addprefix $(BUILDDIR), $(SOURCES:.c=.o))

RCol='\033[0m'    # Reset (sem cor)
Bla='\033[0;30m'  # Preto
Red='\033[0;31m'  # Vermelho
Gre='\033[0;32m'  # Verde
Yel='\033[0;33m'  # Amarelo
Blu='\033[0;34m'  # Azul
Pur='\033[0;35m'  # Roxo
Cya='\033[0;36m'  # Ciano
Whi='\033[0;37m'

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
