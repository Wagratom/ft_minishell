/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:17:14 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/09/01 13:37:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_ht_item	*ht_new_item(char *key, char *value)
{
	t_ht_item	*new;

	if (key == NULL || value == NULL)
		return (NULL);
	new = ft_salloc(sizeof(t_ht_item));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	return (new);
}