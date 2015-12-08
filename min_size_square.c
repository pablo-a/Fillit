/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_size_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:32:43 by pabril            #+#    #+#             */
/*   Updated: 2015/12/08 16:58:46 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		number_pieces(char *str)
{
	int count;
	int index;

	index = 0;
	count = 0;
	while (str[index])
	{
		count++;
		index += 21;
	}
	return (count);
}

int		min_size_square(char *str)
{
	int nb_pieces;
	int size;

	nb_pieces = number_pieces(str);
	size = 0;
	while ((size * size) < (4 * nb_pieces))
		size++;
	return (size);
}
