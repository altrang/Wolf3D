/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:10:41 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/01 17:04:48 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	while (n > 0)
	{
		if (s1c[i] == '\0' || s1c[i] != s2c[i] || s2c[i] == '\0')
			return (s1c[i] - s2c[i]);
		i++;
		n--;
	}
	return (0);
}
