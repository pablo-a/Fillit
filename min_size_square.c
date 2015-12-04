/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_size_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:32:43 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 13:28:16 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		min_size_square(char *str)
{
	int nb_pieces;
	int size;
	int index;

	index = 0;
	nb_pieces = 0;
	size = 0;
	while (str[index])
	{
		nb_pieces++;
		index += 21;
	}
	while ((size * size) < (4 * nb_pieces))
		size++;
	return (size);
}
