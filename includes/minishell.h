/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:42:09 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/08/28 22:17:53 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>

# include <defines.h>

typedef struct s_minishell
{
	bool	debug;

	int		argc;
	char	**argv;
	char	**envp;

	t_list	*lalloc;
}			t_minishell;

/******************************************************************************\
 * CONTROL
\******************************************************************************/

t_minishell	*c(void);
void		initialize_control(int argc, char **argv, char **envp);

bool		debug(void);
void		set_debug(bool verbose);

int			argc(void);
char		**argv(void);
char		**envp(void);

t_list		**lalloc(void);
void		free_memory(void);

/******************************************************************************\
 * LEXER
\******************************************************************************/

char		**lex(char *input);
char		**tokenize(char *input);

char		*skip_single_quotes(char *line);
char		*skip_double_quotes(char *line);

char		*insert_around_two(char *line);
char		*insert_around_one(char *line);
char		*insert_delimiter(char *line);

void		insert_delimiter_before(char *buffer);
void		insert_delimiter_after(char *buffer);
void		insert_delimiter_around(char *buffer);
void		insert_delimiter_around_2(char *buffer);

void		strbuff_insert_before(char *buffer, char insert_me);
void		strbuff_insert_after(char *buffer, char insert_me);
void		strbuff_insert_around(char *buffer, char insert_me);
void		strbuff_insert_around_2(char *buffer, char insert_me);

bool		at_single_quote(char *line);
bool		at_double_quote(char *line);
bool		at_pipe(char *line);
bool		at_space(char *line);
bool		at_truncate(char *line);
bool		at_append(char *line);
bool		at_read_file(char *line);
bool		at_heredoc(char *line);

/******************************************************************************\
 * CRYPTO
\******************************************************************************/

uint32_t	*md5(void *message, size_t mlength);
char		*md5_hex(char *message);

/******************************************************************************\
 * ERRORS
\******************************************************************************/

void		die(void);

#endif
