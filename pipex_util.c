/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:14:06 by sangseo           #+#    #+#             */
/*   Updated: 2025/01/31 07:50:38 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_split(char **s)
{
    char    **temp;

    temp = s;
    while (*temp)
    {
        free(*temp);
        temp++;
    }
    free(s);
}

char    *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    char    *temp;
    int i;

    if (access(cmd, X_OK) == 0)
        return (cmd);
    while (ft_strncmp(*envp, "PATH=", 5) != 0)
        envp++;
    paths = ft_split(*envp + 5, ':');
    i = 0;
    while (paths[i])
    {
        temp = ft_strjoin(paths[i++], "/");
        path = ft_strjoin(temp, cmd);
        free(temp);
        if (access(path, X_OK) == 0)
            break ;
        free(path);
        path = 0;
    }
    free_split(paths);
    if (!path)
        return (0);
    return (path);
}

void    close_all(int *fd)
{
    close(fd[0]);
    close(fd[1]);
}
// void    wait_child(pid_t pid1, pid_t pid2)
// {
//     int *status1;
//     int *status2;

//     while (!(WIFEXITED(*status1) && WIFEXITED(*status2)))
//     {
//         waitpid(pid1, status1, WNOHANG);
//         waitpid(pid2, status2, WNOHANG);
//     }
//     return ;
// }