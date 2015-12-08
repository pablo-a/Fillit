/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:16:02 by pabril            #+#    #+#             */
/*   Updated: 2015/12/08 18:10:03 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*function to resize each piece to the minimum chain*/
void	resize_lst(t_list *lst, int size_square)
{
	int		diff;
	t_list	*tempo;
	char	*str;

	tempo = lst;
	diff = size_square - 4;
	if (size_square == 4)
		return ;
	while (tempo)
	{
		str = create_square(size_square);
		ft_strncpy(str, tempo->content, 4);
		ft_strncpy(str + (size_square + 1), tempo->content + 5, 4);
		ft_strncpy(str + (2 * size_square) + 2, tempo->content + 10, 4);
		ft_strncpy(str + (3 * size_square) + 3, tempo->content + 15, 4);
		tempo->content = str;
		tempo = tempo->next;
	}
}

// function allows to reduce all pieces to a unique piece : AAAA, BBBB, CCCC, ...
void	identify_piece(t_list **lst)
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
	identify_piece(&lst);
	return (lst);
}
