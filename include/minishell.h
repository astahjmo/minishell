/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:22:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/16 14:58:35 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
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
# define PRIME 373
# define DOLLAR "$"
# define SQUOTE "\'"
# define DQUOTE "\""
# define WHITE "\033[0;37m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define STR_LIMIT 1024
# define ENVS_LIMIT 8512
# define SIZEMAX 9223372036854775807
# define ENV_CONTENT_SZ 32367
# define ENV_NAME_SZ 1024
# define HEAP_OVERFLOW_PROTECTION 100000
# define IN_FD 0
# define CHILD_PROCESS 0
# define OUT_FD 1
# define CMD_NOT_FOUND 127

typedef struct s_node		t_node;
typedef struct s_data		t_databus;
typedef t_node				*t_fn_node_apply(char *);
typedef void				t_fn_built_exec(t_node *current);
typedef struct s_env		t_env;
typedef enum e_tokens		t_tokens;
typedef int					t_recipes(t_tokens);
typedef void				*t_genfunc_apply(void *);

// aliases to longer types
typedef long long int		t_lli;
typedef unsigned long long	t_ull;
typedef t_databus			t_dt;
typedef unsigned short		t_bool;

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

typedef struct s_io
{
	int						input;
	int						output;
}							t_io;

enum						e_inputii
{
	I_COMMAND_LINE,
	I_HERE_DOC,
	I_IOFILE
};

typedef struct s_cmds
{
	int						exit_code;
	int						idx;
	t_node					*head;
	t_node					**arr_cmds;
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

typedef struct s_trings
{
	char					*next;
	char					*str2;
	char					*str3;
}							t_strings;

typedef struct s_split
{
	char					**str_arr;
	int						word_count;
}							t_split;

typedef struct s_get_cmd_path
{
	t_split					*split;
	char					*slash_address;
	int						full_possible_size;
	char					*full_possible_name;
	char					*path_str;
}							t_get_cmd_path;

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
int							read_evaluate_print_loop(t_databus *data);
extern char					*get_prompt(void);
extern void					clear_bimatrix(char **arr);
extern void					line_analysis(char *line);
extern void					init_signal(void);
t_fn_node_apply				**init_parser(void);
t_recipes					**init_recipes(void);
extern void					bscanner(t_databus data);
t_bool						has_unclosed_quotes(char *line);
extern void					scanner(t_databus data);
extern t_tokens				get_word_recipe(t_tokens state);
char						*handler_quotes(char *line);
void						tokenizer(void);
char						*single_quotes_handler(char *line, int *acc);
void						string_eat_all(char **word, char hungry);
void						string_eat_until(char **word, char *until);
int							input_is_delimiter(char *s1, char *s2);
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
char						**get_operators_lexemes(void);
char						**get_builtins_arr(void);
char						**get_expansion_lexemes(void);
void						init_env(t_databus *data);
void						free_env(t_databus *data);
void						free_all(t_databus *data);

// 							BUILTINS
void						env_builtin(t_node *current);
void						echo_builtin(t_node *current);
void						exit_builtin(t_node *current);
void						export_builtin(t_node *current);
void						unset_builtin(t_node *current);
void						no_arguments_export_builtin(t_node *current);
int							is_valid_env_name(char *env);
char						*get_content_from_name_alone(char *name);
t_tokens					is_builtin(char *cmd);
void						pwd_builtin(t_node *current);
int							get_pwd_idx(void);
int							get_oldpwd_idx(void);
char						*is_being_initialized(char *new_env);
int							already_exists(t_databus *data, char *env);
t_fn_built_exec				**get_built_func_arr(void);
int							is_initialized_to_zero(char *str);
int							names_are_equal(char *s1, char *s2);
void						get_env_name(char *name, char *env);
int							cmptok(char *s1, char *s2, char tok);
void						get_env_content(char *content, char *name,
								char *env);
int							is_llmin(char *str);
int							names_are_equal(char *s1, char *s2);
char						*strjoinfree_s1(char *s1, char *s2);
int							*getter_inputs(void);
void						cd_builtin(t_node *current);
char						*get_name(char *str);
int							has_too_many_args(void);

// TOKENIZER
char						*expand_dollars(char *line);
void						handle_expansions(void);
char						*trimfree(char *s1, char *set);
int							getindex_of_env(char *to_unset);
char						*trim(char *s, char reject);
void						print_tokens(void);
t_bool						is_quotes(char cmp);
void						print_data(int env);
void						lstadd_back(t_node **lst, t_node *nw);
void						lstfree(t_node **list);
t_node						*create_new_node(void *content, t_tokens tok);
void						retokenize(void);
char						*expand_everything_on_str(char *str);
int							whole_prefix_matched(int i, int len);
char						*handle_frees(char *tmp, char *new_line, char *line,
								int dollar);
char						*remove_quotes(char *list_str);
t_split						*split_envp(char *str, char c);
int							init_redirections(t_node *node);
t_node						*remove_operators(t_node *cursor);
int							pre_executor(t_databus *data);
t_node						*next_node_with_this_token(t_node *node,
								t_tokens token);
char						*get_cmd_path(char *cmd);
void						exec_command(t_node *cmd);
t_io						*command_hook(int cmd_count);
int							*getter_outputs(void);
t_io						*getter_stdio(void);
char						*fmt_s(char *format, char *s1, char *s2, char *s3);
void						one_command(t_node *cmds);
char						**getter_buff(void);
void						sig_handler(int sig);
int							*getter_pipes(void);
void						put_end_line(char *buf, int fd);
void						open_heredoc(t_node *node, t_io *fds, int *status);
int							is_a_command(void);
t_io						*getter_t_ios(void);
int							here_doc(int *status, char *delimiter);
void						open_out_redir(t_node *node, t_io *fds,
								int *status);
void						open_input_redir(t_node *node, t_io *fds,
								int *status);
int							init_input(t_node *node);
int							init_output(t_node *node);
void						set_ext_code_after_builtin(t_node *current);
void						set_ext_code_after_export(int valid);
void						mult_command(t_node **cmds);
#endif
