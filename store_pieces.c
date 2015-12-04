/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:16:02 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 15:12:18 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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
	return (lst);
}
