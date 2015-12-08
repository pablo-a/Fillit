/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:20:37 by pabril            #+#    #+#             */
/*   Updated: 2015/12/08 13:41:43 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char	*create_square(int size)
{
	char	*square;
	int		index;

	index = 0;
	square = ft_strnew((size * 5) + 1);
	if (!square)
		return (NULL);
	while (index <= (size * 5))
	{
		if (index % 4 == 0 && index != 0)
			square[index] = '\n';
		else
			square[index] = '.';
		index++;
	}
	return (square);
}

int		can_place(t_list *lst, int index, char *result, int size_square)
{
	char *str;
	int i;
	int count;

	str = (char *)lst->content;
	i = 0;
	count = 0;
	while (ft_isupper(str[i]) != 1)
		i++;
	while (str[i])
	{
		if (index > (size_square * size_square + 1) - 2)
			return (0);
		if (ft_isupper(str[i]) == 1 && result[index] == '.')
			count++;
		i++;
		index++;
	}
	if (count == 4)
		return (1);
	return (0);
}

void	place(t_list *lst, char **result, int index)
{
	int i;
	char *str;

	i = 0;
	str = (char *)lst->content;
	while (ft_isupper(str[i]) != 1)
		i++;
	while (str[i])
	{
		if (ft_isupper(str[i]) == 1)
			(*result)[index] = str[i];
		i++;
		index++;
	}
}

void	unplace_piece(t_list *lst, char **result)
{
	unsigned char	c;
	int				index;
	char			*str;

	str = (char *)(lst->content);
	index = 0;
	while (ft_isupper(str[index]) != 1)
		index++;
	c = (unsigned char)str[index];
	index = 0;
	while ((*result)[index])
	{
		if ((*result)[index] == c)
			(*result)[index] = '.';
		index++;
	}
}

int		resolution(t_list *lst, int size_square, char *result)
{
	int index;

	index = 0;
	if (lst == NULL)
		return (1);
	while (index < (size_square) * (size_square + 1) - 2)
	{
		while (result[index] != '.')
			index++;
		if (can_place(lst, index, result, size_square) == 1)
		{
			place(lst, &result, index);
			if (resolution(lst->next, size_square, result) == 1)
				return (1);
		}
		index++;
	}
	unplace_piece(lst, &result);
	return (0);
}
