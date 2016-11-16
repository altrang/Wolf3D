/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:01:14 by ataibi            #+#    #+#             */
/*   Updated: 2015/11/27 16:20:10 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*tmp;
	int				tempint;

	i = 0;
	tempint = (int)len;
	tmp = (unsigned char*)b;
	while (i < tempint)
	{
		tmp[i] = c;
		i++;
	}
	return (tmp);
}
