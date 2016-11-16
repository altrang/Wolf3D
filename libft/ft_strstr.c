/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:20:29 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/01 17:06:29 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		while (s1[i + j] && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return ((char*)s1 + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
