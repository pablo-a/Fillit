/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:37:23 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 14:42:30 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		all_squares(char *str)
{
	int block;
	int sign;
	int i;

	i = 0;
	sign = 0;
	block = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#')
		{
			sign++;
			block++;
		}
		if (str[i] == '\n' && sign != 4 && block != 16)
			return (0);
		if (str[i] == '\n' && sign == 4)
			sign = 0;
		if (str[i] == '\n' && str[i - 1] == '\n' && block == 16)
			block = 0;
		if (sign > 4 || block > 16)
			return (0);
		i++;
	}
	if (block != 16)
		return (0);
	else
		return (1);
}

//checker.c

int		sign_checker(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0); //so this would mean it's invalid due to invalid signs
		i++;
	}
	return (1);
}

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
	{
		index++;
		i++;
	}
	while (i % 20 != 0 || i == 0)
	{
		if (i % 20 > 4 && str[index - 5] == '#')// voisin en haut ?
			count++;
		if (i % 20 < 15 && str[index + 5] == '#') // voisin en bas ?
			count++;
		if (i % 5 > 0 && str[index - 1] == '#') // voisin a gauche ?
			count++;
		if (i % 5 < 3 && str[index + 1] == '#') // voisin a droite ?
			count++;
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

//I've checke for the validity of the signs and the squares
//now I need to see if the Tetrimonis are valid as well

int		main(int argc, char **argv)
{
	int		fd;
	char	buff;
	char	buffer[BUFF_SIZE];
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff, 1) != 0 && buff != '\0')
	{
		buffer[i] = buff;//								scanning into the buffer
		i++;
	}
	//buffer[i] = '\0';
	ft_putnbr(min_size_square(buffer));
	ft_putchar('\n');
	t_list *lst;
	lst = store_pieces(buffer);
	while (lst)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
	if (sign_checker(buffer) == 1 && printf("ok1\n"))
		if (all_squares(buffer) == 1 && printf("ok2\n"))
			if (check_valid_piece(buffer) == 1 && printf("ok3\n"))// c'est cette fonction là qui ne valide pas..
				printf("test!\n");
	return (0);
}
