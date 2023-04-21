NAME = minishell
VPATH= ./src ./src/parser ./src/prompt ./src/signals ./src/here_doc ./src/utils ./src/handler_quotes
CC = gcc
CFLAGS = -g -std=gnu18
SOURCES = main.c wait_input.c scanner.c \
		  heredoc.c check_unclosed.c display.c \
		  init_signal.c clear_bimatrix.c \
		  single_quotes_handler.c

BUILDDIR = ./build/
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

MSGBUILD="[$(Gre)+$(RCol)]"
MSGRM="[$(Red)-$(RCol)]"

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(MSGBUILD) Building lib"
	@make --no-print-directory -C ./lib
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(OBJS) -Llib -lft -lreadline -o $@
	@echo "$(MSGBUILD) $@ program has created"
$(BUILDDIR)%.o: %.c
	@test -d $(BUILDDIR) || mkdir $(BUILDDIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I./lib/include -c $< -o $@
	@echo "$(MSGBUILD) building: $@"

clean:
	@echo "$(MSGRM) removing build dir "
	@make --no-print-directory -C ./lib clean
	@rm -rf $(BUILDDIR)

fclean: clean
	@echo "$(MSGRM) removing build dir and executable"
	@make --no-print-directory -C ./lib fclean
	@if test -f $(NAME); then rm -f $(NAME); fi

re: fclean all
