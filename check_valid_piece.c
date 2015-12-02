/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:10:47 by pabril            #+#    #+#             */
/*   Updated: 2015/12/02 18:49:05 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		check_number_pieces(char *str, int index)
{
	int nb;

	nb = 0;
	while (index % 21 != 0 || index == 0)
	{
		if (str[index] == '#')
			nb++;
		index++;
	}
	if (nb != 4)
		return (0);
	return (1);
}

int		check_valid_piece(char *str)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (check_number_pieces(str, index) == 0)
			return (0);

		index += 21;
	}
	return (1);
}
