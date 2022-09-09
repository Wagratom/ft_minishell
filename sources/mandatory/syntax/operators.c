/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:00:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/08 18:39:47 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**operators(void)
{
	static char	*_operators[] = {
		PIPE,
		TRUNCATE, APPEND,
		READ_FILE, HEREDOC,
		NULL};

	return (_operators);
}

bool	is_operator(char *token)
{
	return (ft_str_in_strarr(operators(), token));
}