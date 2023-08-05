/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:22:23 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/28 18:05:03 by vcedraz-         ###   ########.fr       */
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
# define SYNTAX_ERR_MSG "syntax error near unexpected token: %s"
# define TRUE 1
# define FALSE 0
# define WHITE "\033[0;37m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define STR_LIMIT 4027
# define ENVS_LIMIT 8512
# define SIZEMAX 9223372036854775807
# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define ENV_CONTENT_SZ 32367
# define ENV_NAME_SZ 1024
# define CHILD_PROCESS 0
# define WRTE 0
# define READ 1

typedef struct s_node		t_node;
typedef struct s_data		t_databus;
typedef t_node				*t_fn_node_apply(char *);
typedef void				t_fn_built_exec(t_node *current);
typedef enum e_tokens		t_tokens;
typedef int					t_recipes(t_tokens);

// aliases to longer types
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

typedef struct s_cmds
{
	int						exit_code;
	int						idx;
	t_node					*head;
	int						last_cmd_idx;
	t_node					**arr_cmds;
}							t_cmds;

typedef struct s_data
{
	int						exit_status;
	int						number_of_envs;
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
	void					*stream;
}							t_bus;

t_databus					*getter_data(void);
int							read_evaluate_print_loop(t_databus *data);
extern char					*get_prompt(void);
extern void					clear_bimatrix(char **arr);
extern void					init_signal(void);
t_fn_node_apply				**init_parser(void);
t_recipes					**init_recipes(void);
t_bool						has_unclosed_quotes(char *string);
extern t_tokens				get_word_recipe(t_tokens state);
void						tokenizer(void);
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
void						executor(t_databus *data);
char						**get_operators_lexemes(void);
char						**get_builtins_arr(void);
char						**get_expansion_lexemes(void);
void						init_env(t_databus *data);
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

// TOKENIZER
char						*expand_dollars(char *line);
void						handle_expansions(void);
int							getindex_of_env(char *to_unset);
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
t_io						*getter_stdio(void);
char						*fmt_s(char *format, char *s1, char *s2, char *s3);
void						one_command(t_node *cmds);
char						**getter_buff(void);
void						sig_handler(int sig);
int							*getter_pipes(void);
void						put_end_line(char *buf, int fd);
int							is_a_command(void);
t_io						*getter_t_ios(void);
int							here_doc(int *status, char *delimiter);
void						set_ext_code_after_builtin(t_node *current);
void						set_ext_code_after_export(int valid);
void						mult_commands(t_node **cmds);
void						print_tokens_in_arr(t_node **cmds);
void						after_execution(void);
void						free_cmds_arr(t_node **cmds);
char						*test_directory(char *cmd);
void						close_pipe_fds(int *fds);
int							duplicate_stdin(int fd);
int							duplicate_stdout(int fd);
t_bool						handle_empty_string(t_node **cmds, int *cmd_count);
void						wait_all_children(int bkp_fd, int *pids);
pid_t						*arr_of_pid(int total_commands);
t_bool						is_dir(char *path);
t_bool						is_permission_denied(char *cmd);
void						open_redir_io(t_node *node, int *status);
void						execve_error(t_node *cmd);
void						setup_heredoc(int *status, t_node *node);
int							*getter_heredoc_tmp(void);
void						close_heredocs(void);
int							setup_out_redir(int *status, t_node *node,
								t_tokens token, int aux);
int							setup_input_redir(int *status, t_node *node,
								t_tokens token, int aux);
int							*getter_output(void);
int							*getter_input(void);
void						close_all_unused_fd(void);
int							has_too_many_args(t_node *head);
void						invalid_syntax_err_msg(char *s);
void						close_all_fds(void);
int							is_whitespace(char c);
t_node						*next_node_skip_space(t_node *node);
#endif
