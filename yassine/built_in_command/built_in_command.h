/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_command.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:43:56 by yajallal          #+#    #+#             */
/*   Updated: 2023/04/24 14:28:56 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_COMMAND_H
#define BUILT_IN_COMMAND_H

#include "../minishell.h"

typedef struct s_variable
{
	char *name;
	char *value;
} t_variable;

typedef struct s_env
{
	int nb_variables;
	t_variable *variables;
}	t_env;

char *ft_pwd(void);
int ft_strlen2d(char **str);
char *multiple_join(char **path, int length);
void	ft_free2d(char **str);

char	**ft_unset(char *unset_var, char **old_env);
t_env 	*dup_env(char **inherit_env);
void	ft_env(t_env *env);
#endif