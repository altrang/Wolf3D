/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:17:31 by ataibi            #+#    #+#             */
/*   Updated: 2015/11/30 15:55:11 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	i;

	res = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (i < size)
		res += i;
	else
		res += size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, (char*)src, size - ft_strlen(dst) - 1);
	return (res);
}
