/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:46:38 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/15 13:54:04 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	if (s && f)
	{
		if (!(newstr = ft_strnew(ft_strlen(s))))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			newstr[i] = f(i, s[i]);
			i++;
		}
		return (newstr);
	}
	else
		return (NULL);
}
