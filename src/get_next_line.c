/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:50:56 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 01:50:56 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void	ft_gbfree(t_gnline *gnline, t_bstate *bstate)
{
	if (gnline->line != NULL)
	{
		free(gnline->line);
		gnline->line = NULL;
	}
	if (bstate->buf != NULL)
	{
		free(bstate->buf);
		bstate->buf = NULL;
	}
	bstate->beg = 0;
	bstate->nl = 0;
	bstate->end = 0;
}

static int	ft_gbinit(t_gnline *gnline, t_bstate *bstate)
{
	if (bstate->buf == NULL)
	{
		bstate->buf = (char *)malloc(sizeof(*bstate->buf) * BUFFER_SIZE);
		if (bstate->buf == NULL)
			return (0);
	}
	gnline->len = 0;
	gnline->line = (char *)malloc(sizeof(*(gnline->line)));
	if (gnline->line == NULL)
	{
		ft_gbfree(gnline, bstate);
		return (0);
	}
	*(gnline->line) = '\0';
	return (1);
}

static int	ft_dappend(t_gnline *gnline, t_bstate *bstate)
{
	char	*nline;
	size_t	nlen;
	size_t	i;
	size_t	j;

	nlen = gnline->len + bstate->nl - bstate->beg + 1;
	if (*(bstate->buf + bstate->nl) == '\0')
		nlen --;
	nline = (char *)malloc(sizeof(*nline) * (nlen + 1));
	if (nline == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < gnline->len)
		*(nline + i ++) = *(gnline->line + j ++);
	j = bstate->beg;
	while (i < nlen)
		*(nline + i ++) = *(bstate->buf + j ++);
	*(nline + nlen) = '\0';
	gnline->len = nlen;
	free(gnline->line);
	gnline->line = nline;
	return (1);
}

static int	ft_dget(int fd, t_gnline *gnline, t_bstate *bstate)
{
	ssize_t	ret;

	if (bstate->beg == bstate->end)
	{
		ret = read(fd, bstate->buf, BUFFER_SIZE);
		if (ret <= 0)
			return (ret);
		bstate->end = (size_t)ret;
		bstate->beg = 0;
	}
	bstate->nl = bstate->beg;
	while (bstate->nl < bstate->end - 1 && *(bstate->buf + bstate->nl) != '\n')
		bstate->nl ++;
	if (ft_dappend(gnline, bstate) == 0)
		return (-2);
	bstate->beg = bstate->nl + 1;
	if (*(bstate->buf + bstate->nl) == '\n' || ret < BUFFER_SIZE)
		return (1);
	return (2);
}

char	*get_next_line(int fd)
{
	static t_bstate	bstate;
	t_gnline		gnline;
	int				res;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (ft_gbinit(&gnline, &bstate) == 0)
		return (NULL);
	res = 2;
	while (res == 2)
		res = ft_dget(fd, &gnline, &bstate);
	if (res == 1)
		return (gnline.line);
	if (res == 0)
	{
		if (gnline.len == 0)
			ft_gbfree(&gnline, &bstate);
		return (gnline.line);
	}
	ft_gbfree(&gnline, &bstate);
	return (NULL);
}
