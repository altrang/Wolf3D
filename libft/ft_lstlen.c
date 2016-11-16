/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:27:55 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/15 14:34:20 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *begin_list)
{
	int		i;
	t_list	*newlst;

	i = 0;
	if (begin_list)
	{
		newlst = begin_list;
		while (newlst->next != NULL)
		{
			newlst = newlst->next;
			i++;
		}
		return (i + 1);
	}
	return (0);
}
