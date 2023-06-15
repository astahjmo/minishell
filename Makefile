NAME  = minishell
VPATH = ./src \
		./src/parser ./src/prompt ./src/signals \
 		./src/here_doc ./src/utils \
 		./src/handler_quotes \
 		./src/tokenizer \
 		./src/syntax ./src/env ./src \
		./src/builtins ./src/executor
CFLAGS = -g -Wall -Wextra -Werror
SOURCES = main.c wait_input.c tokenizer.c setup_hook.c\
		  heredoc.c check_unclosed.c display.c \
		  init_signal.c clear_bimatrix.c \
		  find_token.c strings_utils.c\
		  tokenizer_operator.c init_parsers.c linked_list.c \
		  tokenizer_string.c analysis.c free_cmds.c recipeWord.c \
		  recipeOperator.c init_recipes.c lexer_strings.c \
		  ft_strjoinfree.c get_env_content.c \
		  env_builtin.c exit_builtin.c executor.c export_builtin.c \
		  unset_builtin.c utils_builtins.c \
		  init_env.c init_statics.c \
	

BUILDDIR = ./objs/
LINCLUDE= ./lib/include
INCLUDE = ./include
LIB = libft.a
OBJS = $(addprefix $(BUILDDIR), $(SOURCES:.c=.o))

RCol='\033[0m'
Bla='\033[0;30m'
Red='\033[0;31m'
Gre='\033[0;32m'
Yel='\033[1;33m'
Blu='\033[0;34m'
Pur='\033[0;35m'
Cya='\033[0;36m'
Whi='\033[0;37m'

MSGBUILD="[$(Gre)+$(RCol)]"
MSGRM="[$(Red)-$(RCol)]"

all: $(NAME)

$(NAME): $(OBJS) 
	@make --no-print-directory supp
	@make --no-print-directory -C ./lib
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -Llib -lft -lreadline -o $@
	@printf "$(MSGBUILD) $@: Program has been created!                                                          \n"

$(BUILDDIR)%.o: %.c
	@printf "$(MSGBUILD) $(NAME): building $@                                                                   \n"
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LINCLUDE) -c $< -o $@

supp:
	@printf "{\n\
        <Readline>\n\
        Memcheck:Leak\n\
        match-leak-kinds: reachable\n\
        ...\n\
        fun:readline\n\
        ...\n\
    }\n\
    {\n\
        <Readline>\n\
        Memcheck:Leak\n\
        match-leak-kinds: definite\n\
        fun:malloc\n\
        fun:xmalloc\n\
        fun:rl_add_undo\n\
        fun:rl_insert_text\n\
        fun:_rl_insert_char\n\
        fun:rl_insert\n\
        fun:_rl_dispatch_subseq\n\
        fun:readline_internal_char\n\
        fun:readline\n\
        ...\n\
    }\n\
    {\n\
        <AddHistory>\n\
        Memcheck:Leak\n\
        match-leak-kinds: reachable\n\
        fun:malloc\n\
        fun:xmalloc\n\
        fun:add_history\n\
        ...\n\
    }\n" > readline.supp


clean:
	@echo "$(MSGRM) removing $(BUILDDIR) dir "
	@make --no-print-directory -C ./lib clean
	@rm -rf $(BUILDDIR)

fclean: clean
	@rm -f readline.supp
	@echo "$(MSGRM) removing $(BUILDDIR) dir and $(NAME) bin"
	@make --no-print-directory -C ./lib fclean
	@if test -f $(NAME); then rm -f $(NAME); fi

re: fclean all
