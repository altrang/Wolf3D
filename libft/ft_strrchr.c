/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:31:00 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/01 17:05:09 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	retchar;
	int		i;
	int		tmp;
	char	*s_cpy;

	retchar = (int)c;
	s_cpy = (char*)s;
	i = 0;
	tmp = -1;
	while (s_cpy[i] != '\0')
	{
		if (s_cpy[i] == retchar)
			tmp = i;
		i++;
	}
	if (tmp != -1)
		return (&(s_cpy[tmp]));
	else if (retchar == '\0')
		return (&(s_cpy[i]));
	else
		return (NULL);
}
