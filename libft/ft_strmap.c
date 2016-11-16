/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:22:03 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/15 13:53:16 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s && f)
	{
		if (!(str = ft_strnew(ft_strlen(s))))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			if (!(str[i] = f(s[i])))
				return (NULL);
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
