/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 02:19:30 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/03 16:48:54 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	argv_err(void)
{
	ft_putstr_fd("\e[31mError: Bad arguments\n\e[0m", 2);
	return (1);
}

void	ft_error(char *s)
{
	perror("\e[31mError");
	if (s)
		ft_putstr_fd(s, 2);
	ft_putstr_fd("\e[0m\n", 2);
	exit(EXIT_FAILURE);
}
