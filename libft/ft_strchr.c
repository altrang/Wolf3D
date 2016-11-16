/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:31:00 by ataibi            #+#    #+#             */
/*   Updated: 2016/03/21 16:53:24 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	retchar;
	int		i;
	char	*s_cpy;

	retchar = (int)c;
	s_cpy = (char*)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == retchar)
			return (&s_cpy[i]);
		i++;
	}
	if (retchar == '\0')
		return (&s_cpy[i]);
	return (NULL);
}
