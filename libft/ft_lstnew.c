/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:41:32 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 12:51:49 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (temp)
	{
		if (content != NULL)
		{
			temp->content = malloc(content_size);
			if (temp == NULL)
				return (NULL);
			ft_memcpy(temp->content, content, content_size);
			temp->content_size = content_size;
		}
		else
		{
			temp->content = NULL;
			temp->content_size = 0;
		}
		temp->next = NULL;
		return (temp);
	}
	return (NULL);
}
