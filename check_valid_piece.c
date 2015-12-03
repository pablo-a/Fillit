/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:10:47 by pabril            #+#    #+#             */
/*   Updated: 2015/12/03 14:27:08 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int		check_shape(char *str, int index)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[index] != '#')
		index++;
	while (index % 20 != 0 || index == 0)
	{
		if (index % 20 > 5 && str[index - 5] == '#') // voisin en haut ?
			count++;
		if (index % 20 < 15 && str[index + 5] == '#') // voisin en bas ?
			count++;
		if (index % 5 > 0 && str[index - 1] == '#') // voisin a gauche ?
			count ++;
		if (index % 5 < 3 && str[index + 1] == '#') // voisin a droite ?
			count++;
		index++;
		while (str[index] != '#' && index % 20 != 0)
			index++;
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
		if (check_number_pieces(str, index) == 0)
			return (0);
		if (check_shape(str, index) == 0)
			return (0);
		index += 21;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int a;
	char *str;

	a = check_valid_piece(av[1]);
	printf("%d\n", a);
	return (0);
}
