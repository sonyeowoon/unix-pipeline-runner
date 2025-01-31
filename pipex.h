/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 02:38:42 by sangseo           #+#    #+#             */
/*   Updated: 2025/01/31 07:51:17 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // perror
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

int argv_err();
void	ft_error();
char    *find_path(char *cmd, char **envp);
void    free_split(char **s);
void    close_all(int *fd);
// void    wait_child(pid_t pid1, pid_t pid2);

#endif