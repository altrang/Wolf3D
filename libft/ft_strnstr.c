/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:42 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/01 17:05:42 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	c;
	char	stmp;
	size_t	length;
	int		i;

	i = 0;
	if ((c = *s2++) != '\0')
	{
		length = ft_strlen(s2);
		while (!i || ft_strncmp(s1, s2, length))
		{
			i = 1;
			if ((stmp = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (stmp != c)
			{
				if ((stmp = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (length > n)
				return (NULL);
		}
		s1--;
	}
	return ((char*)s1);
}
