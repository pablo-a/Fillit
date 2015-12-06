/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:16:02 by pabril            #+#    #+#             */
/*   Updated: 2015/12/06 12:27:02 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


// function allows to reduce all pieces to a unique piece : AAAA, BBBB, CCCC, ...
void	identify_shape(t_list **lst)
{
	int i;
	int piece;
	char *str;
	t_list *tempo;

	piece = 0;
	tempo = *lst;
	while (tempo)
	{
		str = (char *)tempo->content;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '#')
				str[i] = 'A' + piece;
			i++;
		}
		piece++;
		tempo = tempo->next;
	}
}

// store all pieces in a chained list and return her adress
t_list	*store_pieces(char *str)
{
	t_list			*lst;
	t_list			*tempo;
	char			*tmpstr;
	unsigned int	index;

	index = 21;
	lst = ft_lstnew(ft_strsub(str, 0, 20), 20);
	while (str[index] != '\0')
	{
		tmpstr = ft_strsub(str, index, 20);
		tempo = ft_lstnew(tmpstr, 20);
		ft_lstpushback(&lst, tempo);
		index += 21;
	}
	identify_shape(&lst);
	return (lst);
}
