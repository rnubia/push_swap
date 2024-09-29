/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:00:08 by rnubia            #+#    #+#             */
/*   Updated: 2022/05/29 03:22:44 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	ft_free_split(char **wrdarr)
{
	size_t	i;

	i = 0;
	while (*(wrdarr + i) != NULL)
	{
		free(*(wrdarr + i));
		*(wrdarr + i) = NULL;
		i ++;
	}
	free(wrdarr);
}

static size_t	ft_words_cnt(char const *str, char chr)
{
	size_t	wrdcnt;
	char	*ptr;

	ptr = (char *)str;
	wrdcnt = 0;
	while (*ptr != '\0')
	{
		if (*ptr == chr)
			ptr ++;
		else
		{
			wrdcnt ++;
			while (*ptr != chr && *ptr != '\0')
				ptr ++;
		}
	}
	return (wrdcnt);
}

static int	ft_fill_arr(char **wrdarr, const char *str, char chr)
{
	size_t	wrdlen;
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (*ptr == chr)
			ptr ++;
		else
		{
			wrdlen = 1;
			while (*(ptr + wrdlen) != chr && *(ptr + wrdlen) != '\0')
				wrdlen ++;
			*wrdarr = (char *)malloc(sizeof(**wrdarr) * (wrdlen + 1));
			if (*wrdarr == NULL)
				return (0);
			while (*ptr != chr && *ptr != '\0')
				*((*wrdarr)++) = *(ptr ++);
			**wrdarr = '\0';
			*wrdarr -= wrdlen;
			wrdarr ++;
		}
	}
	return (1);
}

char	**ft_split(char const *str, char chr)
{
	size_t	wrdcnt;
	char	**wrdarr;

	if (str == NULL)
		return (NULL);
	wrdcnt = ft_words_cnt(str, chr);
	wrdarr = (char **)malloc(sizeof(*wrdarr) * (wrdcnt + 1));
	if (wrdarr == NULL)
		return (NULL);
	*(wrdarr + wrdcnt) = NULL;
	if (wrdcnt == 0)
		return (wrdarr);
	if (ft_fill_arr(wrdarr, str, chr) == 0)
	{
		ft_free_split(wrdarr);
		return (NULL);
	}
	return (wrdarr);
}
