/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:15 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/06 16:34:36 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*find_key_end(char *var)
{
	while (*var != NULL_CHAR)
	{
		if (*var == SINGLE_QUOTE)
			return (var);
		if (*var == DOUBLE_QUOTE)
			return (var);
		var++;
	}
	return (var);
}

static char	*resolve_value(char *key)
{
	if (ft_streq(key, LAST_EXIT_KEY))
		return (last_exit());
	return (envht_get(key));
}

static char	*insert_value(char *variable)
{
	char	*key;
	char	*value;
	char	*expanded;
	char	*key_end;

	key_end = find_key_end(variable);
	key = ft_substr(variable, 0, key_end - variable);
	value = resolve_value(key);
	expanded = ft_strjoin(value, key_end);
	free(key);
	free(variable);
	return (expanded);
}

static void	insert_values(char *token, char **vars)
{
	char	**first;
	bool	first_is_var;

	first_is_var = *token == DOLLAR;
	first = vars;
	while (*vars != NULL)
	{
		if (vars == first && !first_is_var)
		{
			vars++;
			continue ;
		}
		*vars = insert_value(*vars);
		vars++;
	}
}

char	*expand(char *input)
{
	char	**vars;
	char	*result;

	if (input == NULL)
		return (NULL);
	if (ft_strchr(input, '$') == NULL)
		return (ft_strdup(input));
	vars = isolate_variables(input);
	insert_values(input, vars);
	result = ft_join_strarr(vars);
	ft_free_strarr(vars);
	return (result);
}
