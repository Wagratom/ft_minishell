/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:39:54 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/28 15:05:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	firs_exec_is_builtin(t_parse_list *pipeline)
{
	t_parse_node	*node;
	char			**tokens;

	node = find_first_exec(pipeline);
	if (node == NULL)
		return (false);
	tokens = get_parse_tokens(pipeline);
	if (tokens == NULL)
		return (false);
	if (*tokens == NULL)
		return (false);
	return (is_builtin(*tokens));
}

static void	handle_single_builtin(t_parse_list *pipeline)
{
	int			status;
	t_proc_fds	ioe;

	save_ioe(&ioe);
	status = handle_builtin_sequence(pipeline);
	set_last_exit(status);
	restore_ioe(&ioe);
}

bool	handled_single_builtin(t_parse_list *pipeline)
{
	if (count_parse_pipes(pipeline) > 0)
		return (false);
	if (!firs_exec_is_builtin(pipeline))
		return (false);
	handle_single_builtin(pipeline);
	return (true);
}
