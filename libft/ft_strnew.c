/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:02:22 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/14 15:49:40 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	size++;
	if (!(string = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (size > 0)
	{
		string[size] = 0;
		size--;
	}
	string[0] = 0;
	return (string);
}
