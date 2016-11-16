/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:53:14 by pcalime           #+#    #+#             */
/*   Updated: 2016/03/21 16:38:32 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1

typedef	struct	s_gnl
{
	char		*buf;
	char		*ptr;
}				t_gnl;

int				get_next_line(int const fd, char **line);

#endif
