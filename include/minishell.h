/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:01:06 by johmatos          #+#    #+#             */
/*   Updated: 2023/04/12 19:06:01 by johmatos         ###   ########.fr       */
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
# define TOKENS "< > << >> || && | &"
# define BUILTINS "echo cd pwd export unset env exit"
# define TRUE 1
# define FALSE 0

typedef struct s_tokens	t_tokens;
typedef struct s_tree	t_ast;
typedef struct s_data	t_databus;
enum e_tokens {
	T_INPUT_REDIR,
	T_OUT_REDIR,
	T_O_OUT_REDIR,
	T_HERE_DOC,
	T_OR_LOGIC,
	T_AND_LOGIC,
	T_PIPE,
	T_FOREGROUND,
	T_WORD
};

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

typedef struct s_data {
	enum e_inputii	type_stream;
	char			*stream;
	char			**env_buff;
}					t_databus;

typedef struct s_tokens {
	enum e_tokens	type;
	char			*word;
}					t_tokens;

typedef struct s_tree {
	enum e_tokens	token;
	void			*left;
	void			*right;
}					t_ast;

typedef struct b_bus {
	enum e_inputii	input_state;
	void			*stream;
}					t_bus;

typedef int				t_bool;
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

#endif // !
