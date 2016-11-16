/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:42:42 by ataibi            #+#    #+#             */
/*   Updated: 2015/11/30 15:27:07 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		pos;

	i = ft_strlen(s1);
	pos = 0;
	while (n)
	{
		s1[i] = s2[pos];
		pos++;
		i++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
