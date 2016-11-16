/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:34:03 by ataibi            #+#    #+#             */
/*   Updated: 2015/11/30 18:45:59 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	tmp;
	unsigned char	*s_cpy;
	int				tempint;

	i = 0;
	tempint = (int)n;
	tmp = (unsigned char)c;
	s_cpy = (unsigned char*)s;
	while (i < tempint)
	{
		if (s_cpy[i] == (int)tmp)
			return (&(s_cpy[i]));
		i++;
	}
	return (NULL);
}
