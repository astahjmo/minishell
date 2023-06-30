/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:22:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/28 15:39:16 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/include/libft.h"
# include <errno.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# define JOINED 1
# define NOT_JOINED 0
# define WITH_ENV 1
# define WITHOUT_ENV 0
# define PREFIX_LEN 30
# define BUILTINS "echo cd pwd export unset env exit"
# define TRUE 1
# define FALSE 0
# define ARR_MAX_BUFF (int)1e3
# define PRIME 373
# define DOLLAR '$'
# define SQUOTE '\''
# define DQUOTE '"'
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define STR_LIMIT 1024
# define ENVS_LIMIT 1024
# define SIZEMAX 9223372036854775807

typedef struct s_node		t_node;
typedef struct s_data		t_databus;
typedef t_node				*t_fn_node_apply(char *);
typedef void				t_fn_built_exec(t_node *current);
typedef short int			t_bool;
typedef struct s_env		t_env;
typedef enum e_tokens		t_tokens;
typedef int					t_recipes(t_tokens);
typedef void				*t_genfunc_apply(void *);

// aliases to longer types
typedef long long int		t_lli;
typedef unsigned long long	t_ull;
typedef t_databus			t_dt;
typedef unsigned short		t_ushort;

typedef enum e_tokens
{
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
	T_INVALID = -1,
	T_SPACE = 10
}							t_tokens;

enum						e_inputii
{
	I_COMMAND_LINE,
	I_HERE_DOC,
	I_IOFILE
};

typedef struct s_cmds
{
	int						exit_code;
	t_node					*head;
}							t_cmds;

typedef struct s_data
{
	int						exit_status;
	int						number_of_envs;
	enum e_inputii			type_stream;
	char					*stream;
	char					env[ENVS_LIMIT][STR_LIMIT];
	t_cmds					*cmds;
	char					*prompt;
	char					*env_to_unset;
	char					*new_env;
	char					**envp;
}							t_databus;

typedef struct s_node
{
	enum e_tokens			token;
	char					*str;
	t_node					*next;
}							t_node;

typedef struct b_bus
{
	enum e_inputii			input_state;
	void					*stream;
}							t_bus;

t_databus					*getter_data(void);
int							repl(t_databus *data);
extern char					*get_prompt(void);
extern void					clear_bimatrix(char **arr);
extern void					line_analysis(char *line);
extern void					init_signal(void);
t_fn_node_apply				**init_parser(void);
t_recipes					**init_recipes(void);
extern void					bscanner(t_databus data);
extern int					check_unclosed_quotes(char *line, char *delimiter);
extern void					scanner(t_databus data);
extern t_tokens				get_word_recipe(t_tokens state);
char						*handler_quotes(char *line);
void						tokenizer(void);
char						*single_quotes_handler(char *line, int *acc);
void						string_eat_all(char **word, char hungry);
void						string_eat_until(char **word, char *until);
int							string_is_equal(char *s1, char *s2);
t_tokens					get_token(char *find);
int							init_heredoc(t_node *node);
t_node						*tokenizer_operator(char *list);
t_node						*list_last_node(t_node *head);
t_node						*list_node_new(void);
t_node						*tokenizer_string(char *line);
void						list_add_back(t_node *back, t_node *node);
void						list_addfront(t_node *node, t_node *front);
void						string_eat_at_next_token(char **wordt);
void						main_setup_hook(t_databus *data);
void						free_cmds(t_cmds *cmds);
int							get_operator_recipe(t_tokens token);
char						*get_token_string(t_tokens token);
int							is_valid_syntax(t_node *head);
void						string_eat_at(char **word, char at);
t_tokens					get_expansion(char *line);
char						*trim_key(char *key);
char						*expand_dolar(char *line);
char						*strjoin_free(char *s1, char *s2);
void						executor(t_databus *data);
char						**get_lexemes(void);
char						**get_builtins(void);
char						**get_expansion_lexes(void);
void						init_env(t_databus *data);
void						free_env(t_databus *data);
void						free_all(t_databus *data);

// 							BUILTINS
void						env_builtin(t_node *current);
void						echo_builtin(t_node *current);
void						exit_builtin(t_node *current);
void						export_builtin(t_node *current);
void						unset_builtin(t_node *current);
void						alt_env_builtin(t_node *current);
int							is_valid_env_name(char *env);
char						*get_content_from_name_alone(char *name);
t_tokens					is_builtin(t_databus *data);
void						pwd_builtin(t_node *current);
int							pwd_idx(void);
int							oldpwd_idx(void);
char						*is_being_initialized(char *new_env);
int							already_exists(t_databus *data, char *env);
t_fn_built_exec				**get_built_func(void);
int							is_initialized_to_zero(char *str);
int							names_are_equal(char *s1, char *s2);
void						get_env_name(char *name, char *env);
int							cmptok(char *s1, char *s2, char tok);
void						get_env_content(char *content, char *name,
								char *env);
int							is_llmin(char *str);
int							names_are_equal(char *s1, char *s2);
char						*strjoinfree_s1(char *s1, char *s2);
int							here_doc(int *status, char *delimiter);
int							*getter_heredoc_fd(void);
void						cd_builtin(t_node *current);
int							overwrite_env(t_databus *data, char *new_env);
char						*get_name(char *str);
int							has_too_many_args(t_databus *data);

// TOKENIZER
char						*expand_dollar(char *line);
void						handle_expansions(void);
char						*trimfree(char *s1, char *set);
int							getindex_of_env(char *to_unset);
char						*trim(char *s, char reject);
void						print_tokens(void);
int							is_quotes(char cmp);
void						print_data(int env);
void						lstadd_back(t_node **lst, t_node *nw);
void						lstfree(t_node **list);
t_node						*create_new_node(void *content, t_tokens tok);
void						retokenize(void);
char						*expand_everything_on_str(char *str);
int							whole_prefix_matched(int i, int len);

#endif
