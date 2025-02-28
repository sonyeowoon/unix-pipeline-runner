/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:27:05 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/03 17:28:33 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *av, char **envp, int file)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_split(cmd);
		close(file);
		ft_error("Not available path");
	}
	if (execve(path, cmd, envp) == -1)
	{
		close(file);
		ft_error(NULL);
	}
}

void	fir_child_process(char **av, char **envp, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error(NULL);
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error(NULL);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(NULL);
	close(fd[0]);
	execute_cmd(av[2], envp, infile);
}

void	sec_child_process(char **av, char **envp, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error(NULL);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(NULL);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error(NULL);
	close(fd[1]);
	execute_cmd(av[3], envp, outfile);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		return (argv_err());
	if (pipe(fd) == -1)
		ft_error(NULL);
	pid1 = fork();
	if (pid1 == -1)
		ft_error(NULL);
	if (pid1 == 0)
		fir_child_process(av, envp, fd);
	else
		pid2 = fork();
	if (pid1 != 0 && pid2 == -1)
		ft_error(NULL);
	else if (pid1 != 0 && pid2 == 0)
		sec_child_process(av, envp, fd);
	close_all(fd);
	if (pid1 != 0 && pid2 != 0)
		wait_child(pid1, pid2);
	return (0);
}
