/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:50:32 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 16:38:09 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *tempo;

	if (new == NULL)
		return ;
	tempo = *alst;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = new;
}
