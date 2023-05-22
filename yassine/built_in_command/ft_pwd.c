/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:29:26 by yajallal          #+#    #+#             */
/*   Updated: 2023/05/22 12:46:58 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in_command.h"

void ft_pwd(t_command *cmd)
{
	char *buffer;

	buffer = NULL;
	ft_putstr_fd(getcwd(buffer, 0), 1);
	ft_putchar_fd('\n', 1);
	cmd->g_info->exit_code = 0;
}