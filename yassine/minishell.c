/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:27:57 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/24 16:18:18 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	if (ac > 1)
		return (0);
	if (av[1])
		return (0);
	int i;
	char *input;
	char *tmp;
	char **split;
	t_command **cmd;
	t_global_info *g_info;
	cmd = malloc(sizeof(t_command *));
	cmd[0] = malloc(sizeof(t_command));
	g_info = malloc(sizeof(t_global_info));
	g_info->environ = dup_env(env);
	g_info->export_env = dup_env(env);
	g_info->exit_code = 0;
	g_info->env_array = convert_env_array(g_info->environ);
	g_info->nb_pipe = 2;
	while(1)
	{
		input = readline("\e[1;36m➜  \e[1;33mminishell \e[1;32m✗ \e[0;00m");
		if(!input)
			exit(g_info->exit_code);
		input = ft_strtrim(input, " ");
		if (ft_strlen(input) != 0)
		{
			add_history(input);
			split = lexer(input, g_info);
			if(split != NULL)
			{
				if(syntx_error_a(split, g_info) && syntx_error_b(split, g_info))
				{
					cmd = rmplir_strct(split, g_info);
					pipes(cmd, g_info);				
				}
			}
		}
		else
			g_info->exit_code = 0;
		// system("leaks minishell");
	}
}
