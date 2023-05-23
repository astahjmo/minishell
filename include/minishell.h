/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:04 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/23 17:50:41 by johmatos         ###   ########.fr       */
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
# define BUILTINS "echo cd pwd export unset env exit"
# define TRUE 1
# define FALSE 0
# define ARR_MAX_BUFF (int)1e4
# define PRIME 373
# define DOLLAR '$'
# define SQUOTE '\''
# define DQUOTE '"'

typedef struct s_node	t_node;
typedef struct s_data	t_databus;
typedef t_node			*t_fn_node_apply(char*);
typedef short int		t_bool;
typedef struct s_env	t_env;
typedef enum e_tokens	t_tokens;
typedef int				t_recipes(t_tokens);

typedef enum e_tokens{
	T_INITIAL = 0,
	T_HERE_DOC = 1,
	T_O_OUT_REDIR = 2,
	T_OR_LOGIC = 3,
	T_AND_LOGIC = 4,
	T_PIPE = 5,
	T_FOREGROUND = 6,
	T_INPUT_REDIR = 7,
	T_OUT_REDIR = 8,
	T_WORD = 9,
	T_INVALID = -1
}			t_tokens;

enum e_inputii {
	I_COMMAND_LINE,
	I_HERE_DOC,
	I_IOFILE
};

typedef struct s_env{
	char	*value;
	t_env	*next;
}				t_env;

typedef struct s_infoenv{
	int			colision;
	long long	count;
	t_env		**bucket;
}				t_infoenv;

typedef struct s_cmds {
	int			exit_code;
	t_node		*head;
}				t_cmds;

typedef struct s_data {
	enum e_inputii	type_stream;
	char			*stream;
	t_infoenv		*env;
	t_cmds			*cmds;
}					t_databus;

typedef struct s_node {
	enum e_tokens	token;
	char			*data;
	int				length;
	t_node			*next;
	t_node			*back;
}					t_node;

typedef struct b_bus {
	enum e_inputii	input_state;
	void			*stream;
}					t_bus;

extern int				wait_input(t_databus data);
extern char				*get_prompt(void);
extern void				clear_bimatrix(char **arr);
extern void				line_analysis(char *line);
extern void				init_signal(void);
t_fn_node_apply			**init_parser(void);
t_recipes				**init_recipes(void);
extern void				bscanner(t_databus data);
extern char				*here_doc(char	*line, char *quote);
extern int				check_unclosed_quotes(char *line, char *delimiter);
extern void				scanner(t_databus data);
extern char				ft_interpol_wrapper(char *pattern, ...);
extern t_tokens			get_word_recipe(t_tokens state);
char					*handler_quotes(char *line);
void					tokenizer(t_databus data);
char					*single_quotes_handler(char *line,int *acc);
void					string_eat_all(char **word, char hungry);
void					string_eat_until(char **word, char *until);
t_tokens				get_token(char *find);
t_bool					string_is_equal(char *string, char find);
t_node					*tokenizer_operator(char *list);
t_node					*ft_last_node(t_node *head);
t_node					*ft_node_new(void);
t_node					*tokenizer_string(char *line);
void					ft_add_back(t_node *back, t_node *node);
void					ft_addfront(t_node *node, t_node *front);
void					string_eat_at_next_token(char **wordt);
void					main_setup_hook(t_databus *data);
void					free_cmds(t_cmds *cmds);
int						get_operator_recipe(t_tokens);
char					*get_token_string(t_tokens token);
int						sintax_analysis(t_node *head);
void					ft_add_env_back(t_env *node, t_env *new);
t_env					*ft_env_new(void);
t_env					*ft_last_env(t_env *head);
void					*init_environ(char *envp[], t_infoenv *environ);
long long int			hash_map(char *string);
void					string_eat_at(char **word, char at);
void					free_env(t_infoenv *env);
void					ft_print_env(t_infoenv *env);
t_tokens				get_expansion(char *line);
char					*get_env(char *env);
t_env					**get_bucket(void);
char					*trim_key(char *key);
char				*expand_dolar(char *line);
#endif // !
