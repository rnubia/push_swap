/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 01:51:09 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 01:51:09 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

typedef struct s_bstate
{
	size_t	beg;
	size_t	nl;
	size_t	end;
	char	*buf;
}	t_bstate;

typedef struct s_gnline
{
	size_t	len;
	char	*line;
}	t_gnline;

char	*get_next_line(int fd);

#endif
