/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:37:09 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/04 08:25:41 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
		ptr ++;
	return (ptr - str);
}

void	ft_putstr_fd(const char *str, int fd)
{
	if (fd >= 0)
		write(fd, str, ft_strlen(str));
}

void	ft_putendl_fd(const char *str, int fd)
{
	if (fd >= 0)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}

void	ft_error(const char *error)
{
	ft_putendl_fd(error, STDERR_FILENO);
}

void	ft_exit(const char	*error)
{
	ft_putstr_fd(ERROR_SYS, STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
