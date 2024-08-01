/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:29:40 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/01 16:12:21 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc(int heredoc[2], char *delim)
{
	char	buffer[4096];
	char	*eof;
	ssize_t	size;

	if (pipe(heredoc) == -1)
		exit_perror("pipe", 1);
	eof = ft_strjoin(delim, "\n");
	ft_memset(buffer, 0, 4096);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		size = read(0, buffer, 4096);
		if (size <= 0 || !ft_strncmp(buffer, eof, ft_strlen(eof)))
		{
			free(eof);
			break ;
		}
		write(heredoc[1], buffer, size);
		ft_memset(buffer, 0, size);
	}
	close(heredoc[1]);
	return (heredoc[0]);
}
