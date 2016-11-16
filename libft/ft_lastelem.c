/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastelem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:37:04 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/15 14:39:10 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lastelem(t_list *begin_list)
{
	t_list	*newlst;

	newlst = begin_list;
	while (newlst->next != NULL)
		newlst = newlst->next;
	return (newlst);
}
