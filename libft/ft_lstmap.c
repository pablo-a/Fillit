/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:47:17 by pabril            #+#    #+#             */
/*   Updated: 2015/12/01 10:48:21 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elemt))
{
	t_list *tempo;
	t_list *tempo_late;
	t_list *ret;
	t_list *save;

	tempo_late = NULL;
	save = NULL;
	while (lst != NULL && f != NULL)
	{
		ret = f(lst);
		tempo = ft_lstnew(ret->content, ret->content_size);
		if (tempo == NULL)
			return (NULL);
		tempo->next = NULL;
		if (tempo_late != NULL)
			tempo_late->next = tempo;
		tempo_late = tempo;
		lst = lst->next;
		if (save == NULL)
			save = tempo;
	}
	return (save);
}
