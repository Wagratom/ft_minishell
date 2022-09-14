/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:11:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/14 15:36:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle_linebreak(bool linebreak)
{
	if (linebreak)
		printf("\n");
}

static void	handle_flags(char ***tokens, bool *linebreak)
{
	(*tokens)++;
	*linebreak = true;
	if (ft_streq(**tokens, ECHO_NO_LINEBREAK_FLAG))
	{
		*linebreak = false;
		(*tokens)++;
	}
}

static void	print_tokens(char **tokens)
{
	while (*tokens != NULL)
	{
		printf("%s", *tokens);
		if (*(tokens + 1) != NULL)
			printf(" ");
		tokens++;
	}
}

bool	echo(char **tokens)
{
	bool	linebreak	;

	if (tokens == NULL || *tokens == NULL)
		return (false);
	handle_flags(&tokens, &linebreak);
	print_tokens(tokens);
	handle_linebreak(linebreak);
	return (true);
}
