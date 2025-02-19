/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:10:13 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/02 11:21:14 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../includes/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

int		get_infile(char *file);
int		get_outfile(char *file);
int		get_outfile_append(char *file);
int		here_doc(int heredoc[2], char *delim);

char	**get_paths(char **envp);
char	*get_command_path(char **paths, char *cmd);
int		check_command(char *cmd, char **paths, int is_last);
void	multi_execute(int n, char **cmds, int fd[2], char **paths);

void	exit_perror(char *s, int code);
void	exit_error(char *s);
void	exit_command_not_found(char *cmd);
int		exit_code(int overwrite_code);

#endif
