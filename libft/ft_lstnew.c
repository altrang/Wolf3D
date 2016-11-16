/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:42:16 by ataibi            #+#    #+#             */
/*   Updated: 2015/12/01 19:06:39 by ataibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*my_list;

	if (!(my_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		my_list->content = NULL;
		my_list->content_size = 0;
	}
	else
	{
		my_list->content = malloc(content_size);
		if (!my_list->content)
			return (NULL);
		ft_memcpy(my_list->content, content, content_size);
		my_list->content_size = content_size;
	}
	my_list->next = NULL;
	return (my_list);
}
