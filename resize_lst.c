/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:27:44 by pabril            #+#    #+#             */
/*   Updated: 2015/12/11 15:26:55 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*function to resize each piece to the same size of the final square chain*/
int		resize_lst(t_list *lst, int size_square, int nb)
{
	int		diff;
	t_list	*tempo;
	char	*str;

	tempo = lst;
	diff = size_square - 4;
	if (size_square < 4)
	{
		if (reduce_lst(lst, size_square) == 0)
			return (0);
		return (1);
	}
	while (tempo)
	{
		str = create_square(size_square);
		ft_strncpy(str, tempo->content, nb);
		ft_strncpy(str + (size_square + 1), tempo->content + nb + 1, nb);
		ft_strncpy(str + (2 * size_square) + 2, tempo->content + (2 * nb) + 2, nb);
		ft_strncpy(str + (3 * size_square) + 3, tempo->content + (3 * nb) + 3, nb);
		tempo->content = str;
		tempo = tempo->next;
	}
	return (1);
}

int		column_and_line_empty(char *str)
{
	if (str[3] == '.' && str[8] == '.' && str[13] == '.' && str[15] == '.'
			&& str[16] == '.' && str[17] == '.' && str[18] == '.')
		return (1);
	return (0);
}

int		can_reduce(t_list *lst, int size_square)
{
	int i;
	char *src;

	i = 0;
	src = lst->content;
	if (size_square == 2)
	{
		if (ft_isupper(src[0]) && ft_isupper(src[1]) && ft_isupper(src[5]) && ft_isupper(src[6]))
		{
			ft_putendl("hello");
			return (1);
		}
		return (0);
	}
	while (lst)
	{
		src = lst->content;
		if (column_and_line_empty(src) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

char	*reduce(t_list *lst, int size_square)
{
	char *resized;
	char *src;

	src = lst->content;
	if (size_square == 2)
	{
		resized = create_square(2);
		ft_strncpy(resized, src, 2);
		ft_strncpy(resized + 3, src + 5, 2);
	}
	if (size_square == 3)
	{
		resized = create_square(3);
		ft_strncpy(resized, src, 3);
		ft_strncpy(resized + 4, src + 5, 3);
		ft_strncpy(resized + 8, src + 10, 3);
	}
	return (resized);
}

int		reduce_lst(t_list *lst, int size_square)
{
	t_list *tempo;
	int index;

	index = 0;
	tempo = lst;
	while (tempo)
	{
		if (can_reduce(tempo, size_square) == 1)
		{
			tempo->content = reduce(tempo, size_square);
			tempo = tempo->next;
		}
		else
			return (0);
	}
	return (1);
}
