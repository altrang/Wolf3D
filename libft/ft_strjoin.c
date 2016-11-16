/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrang <atrang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:01:09 by ataibi            #+#    #+#             */
/*   Updated: 2016/02/28 18:25:03 by atrang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		ret_index;
	int		s1_index;
	int		s2_index;

	ret_index = 0;
	s1_index = -1;
	s2_index = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[++s1_index])
	{
		ret[ret_index] = s1[s1_index];
		ret_index++;
	}
	while (s2[++s2_index])
	{
		ret[ret_index] = s2[s2_index];
		ret_index++;
	}
	ret[ret_index] = '\0';
	return (ret);
}
