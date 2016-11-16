/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:12:31 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/15 13:52:09 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int		length;

	if (s)
	{
		length = ft_strlen(s);
		if (s == NULL || f == NULL)
			return ;
		while (length)
		{
			f(s);
			s++;
			length--;
		}
	}
}
