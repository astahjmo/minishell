NAME  = minishell
VPATH = ./src \
		./src/parser ./src/prompt ./src/signals \
 		./src/utils \
 		./src/handler_quotes \
 		./src/tokenizer ./src/expansions \
 		./src/syntax ./src/env ./src \
		./src/builtins ./src/executor ./src/redirections ./src/utils

CFLAGS = -g -Wall -Wextra -Werror
SOURCES = main.c wait_input.c tokenizer.c setup_hook.c\
		  has_unclosed_quotes.c display.c ft_linked_list.c \
	  	  init_signal.c clear_bimatrix.c retokenize.c handle_expansions.c \
		  find_token.c strings_utils.c strjoinfree_s1.c print_data.c\
		  tokenizer_operator.c init_parsers.c linked_list.c \
		  tokenizer_string.c analysis.c free_cmds.c recipeWord.c \
		  recipeOperator.c init_recipes.c lexer_strings.c \
		  strjoinfree.c free_all.c cd_builtin.c fmt_s.c put_end_line.c \
		  env_builtin.c exit_builtin.c executor.c export_builtin.c echo_builtin.c \
		  unset_builtin.c utils_builtins_01.c utils_builtins_02.c utils_builtins_03.c \
		  init_env.c init_statics.c is_llmin.c heredoc_utils.c pwd_builtin.c \
		  init_t_file_io.c init_redirections.c open_redirections.c \
		  expansion_utils.c print_tokens.c heredoc.c\
		  utils_executor.c one_command.c exec_command.c get_cmd_path.c \
		  split_envp.c command_setuphook.c pre_executor.c is_a_command.c \

LIB_SRCS = ft_strlen.c ft_strdup.c ft_substr.c ft_itoa.c \
				 ft_split.c ft_strlcpy.c ft_isalpha.c \
				 ft_isalnum.c ft_putstr_fd.c ft_memmove.c ft_strncmp.c \
				 ft_strchr.c ft_bzero.c ft_strnstr.c ft_memset.c ft_isdigit.c \
				 ft_strjoin.c ft_atoull.c ft_atoi.c ft_memcpy.c ft_calloc.c \
				 ft_strlcat.c ft_strcmp.c ft_safe_free.c ft_printf.c ft_putendl_fd.c \

BUILDDIR = ./objs/
LINCLUDE= ./lib/include
INCLUDE = ./include
LIB = libft.a
MINILIB = lib/mini_libft.a
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
cleanline='\033[2K'

MSGBUILD="[$(Gre)+$(RCol)]"
ALT_MSGBUILD="[$(Cya)+$(RCol)]"
MSGRM="[$(Red)-$(RCol)]"

all: $(NAME)

ifdef ACTIONS
    CC = clang-12
endif

makelib:
	@make minishell -C lib --no-print-directory

$(NAME): $(OBJS) makelib
	@make --no-print-directory supp
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) $(MINILIB) -lreadline -o $@
	@printf "\n$(ALT_MSGBUILD) $@: Program has been created!         \n"

$(BUILDDIR)%.o: %.c
	@printf "$(MSGBUILD) $(NAME): building $@                                                                   \r"
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	@printf "$(MSGBUILD) $(NAME): building $@                        \n"
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
	@printf "$(MSGRM) removing $(BUILDDIR) dir                   \n"
	@make --no-print-directory -C ./lib clean
	@rm -rf $(BUILDDIR)

fclean: clean
	@rm -f readline.supp
	@printf "$(MSGRM) removing $(BUILDDIR) dir and $(NAME) bin   \n"
	@make --no-print-directory -C ./lib fclean
	@if test -f $(NAME); then rm -f $(NAME); fi

re: fclean all
