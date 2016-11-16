/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:08:34 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/15 13:51:27 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		length;
	int		i;

	if (s)
	{
		length = ft_strlen(s);
		i = 0;
		while (i < length)
		{
			s[i] = '\0';
			i++;
		}
	}
}