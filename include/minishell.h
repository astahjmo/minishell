/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:01:06 by johmatos          #+#    #+#             */
/*   Updated: 2023/02/08 19:40:35 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/include/libft.h"
# include <readline/readline.h>
# include <linux/limits.h>
#include <stdlib.h>
# define PREFIX_LEN 11

int		wait_input(int argc, char *argv[], char *envp[]);
char	*get_prompt(void);
#endif // !
