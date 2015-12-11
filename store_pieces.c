/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:16:02 by pabril            #+#    #+#             */
/*   Updated: 2015/12/11 16:11:12 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	identify_piece(t_list **lst)
{
	int		i;
	int		piece;
	char	*str;
	t_list	*tempo;

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

int		empty_left_and_top(char *str)
{
	if (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
		return (1);
	if (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
		return (2);
	return (0);
}

char	*replace_piece(char *str, int cas)
{
	char *replace;

	replace = create_square(4);
	if (cas == 1)
	{
		ft_strncpy(replace, str + 5, 4);
		ft_strncpy(replace + 5, str + 10, 4);
		ft_strncpy(replace + 10, str + 15, 4);
	}
	else
	{
		ft_strncpy(replace, str + 1, 3);
		ft_strncpy(replace + 5, str + 6, 3);
		ft_strncpy(replace + 10, str + 11, 3);
		ft_strncpy(replace + 15, str + 16, 3);
	}
	return (replace);
}

void	place_piece(t_list **lst)
{
	t_list	*tempo;
	char	*str;

	tempo = *lst;
	while (tempo)
	{
		str = (char *)tempo->content;
		while (empty_left_and_top(str) != 0)
			str = replace_piece(str, empty_left_and_top(str));
		tempo->content = str;
		tempo = tempo->next;
	}
}

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
	place_piece(&lst);
	identify_piece(&lst);
	return (lst);
}
