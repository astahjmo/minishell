/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:01:06 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/01 00:40:38 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/include/libft.h"
# include <readline/readline.h>
# include <linux/limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# define PREFIX_LEN 11
# define TOKENS "( ) > >> < << = * & && | ||"
# define BUILTIN "echo cd pwd export unset env exit"

enum e_tokens {
	LEFT_PARENT,
	RIGHT_PARENT,
	GREATER,
	D_GREATER,
	LESS,
	D_LESS,
	EQUAL,
	STAR,
	AMPERSEND,
	D_AMPERSEND,
	PIPE,
	D_PIPE,
	WORD
} ;

typedef struct s_tokens	t_tokens;

typedef struct s_tokens {
	enum e_tokens	type;
	t_tokens		*next;
	char			*word;
}					t_tokens;

int		wait_input(int argc, char *argv[], char *envp[]);
char	*get_prompt(void);
void	line_analysis(char *line);
#endif // !
