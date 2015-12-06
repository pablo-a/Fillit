/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:20:37 by pabril            #+#    #+#             */
/*   Updated: 2015/12/06 12:35:49 by pabril           ###   ########.fr       */
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

char	*resolution(t_list *lst, int size_square)
{
	char *square;

	square = create_square(size_square);
}
