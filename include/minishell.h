/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:01:06 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 05:31:49 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/include/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# define PREFIX_LEN 30
# define TOKENS "<< >> || && | & < >"
# define BUILTINS "echo cd pwd export unset env exit"
# define TRUE 1
# define FALSE 0

typedef struct s_node	t_node;
typedef struct s_data	t_databus;
typedef t_node			*t_fn_node_apply(char*);

typedef enum e_tokens{
	T_HERE_DOC,
	T_O_OUT_REDIR,
	T_OR_LOGIC,
	T_AND_LOGIC,
	T_PIPE,
	T_FOREGROUND,
	T_INPUT_REDIR,
	T_OUT_REDIR,
	T_WORD
}			t_tokens;

enum e_inputii {
	I_COMMAND_LINE,
	I_HERE_DOC,
	I_IOFILE
};

enum e_state {
	e_quote,
	e_token,
	e_blank,
	e_redirect,
	e_operator
};

typedef enum e_bool{
	true,
	false
}		t_bool;

typedef struct s_data {
	enum e_inputii	type_stream;
	char			*stream;
	char			**env_buff;
}					t_databus;

typedef struct s_node {
	enum e_tokens	token;
	t_node			*next;
}					t_node;

typedef struct b_bus {
	enum e_inputii	input_state;
	void			*stream;
}					t_bus;

typedef char			**t_lexeme;

extern int				wait_input(t_databus data);
extern char				*get_prompt(void);
extern void				clear_bimatrix(char **arr);
extern void				line_analysis(char *line);
extern void				init_signal(void);
extern void				bscanner(t_databus data);
extern char				*here_doc(char	*line, char *quote);
extern int				check_unclosed_quotes(char *line, char *delimiter);
extern void				scanner(t_databus data);
extern char				ft_interpol_wrapper(char *pattern, ...);
extern void				single_quotes_handler(char *line);
void					tokenizer(t_databus data);
t_tokens				get_token(char *find);
void					string_eat_until(char **word, char *until);
t_bool					string_is_equal(char *string, char find);
void					string_eat_all(char **word, char hungry);
t_node					*tokenizer_operator(char *list);
t_fn_node_apply			**init_parser(void);
#endif // !
