/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_pieces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:06:51 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 16:17:51 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		check_number_pieces(char *str, int index)
{
	int nb;
	int i;

	i = 0;
	nb = 0;
	while (i < 20)
	{
		if (str[index] == '#')
			nb++;
		index++;
		i++;
	}
	if (nb != 4)
		return (0);
	return (1);
}

int		count_neighbours(int count, char *str, int index, int i)
{
	if (i % 20 > 4 && str[index - 5] == '#')// voisin en haut ?
		count++;
	if (i % 20 < 15 && str[index + 5] == '#') // voisin en bas ?
		count++;
	if (i % 5 > 0 && str[index - 1] == '#') // voisin a gauche ?
		count++;
	if (i % 5 < 3 && str[index + 1] == '#') // voisin a droite ?
		count++;
	return (count);
}

int		check_shape(char *str, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[index] != '#')
	{
		index++;
		i++;
	}
	while (i % 20 != 0 || i == 0)
	{
		count = count + count_neighbours(0, str, index, i);
		index++;
		i++;
		while (str[index] != '#' && i % 20 != 0)
		{
			index++;
			i++;
		}
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		check_valid_piece(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (check_number_pieces(str, index) == 0 && printf("false numer of #\n"))
			return (0);
		if (check_shape(str, index) == 0 && printf("forme non ok\n"))
			return (0);
		index += 21;
	}
	return (1);
}
