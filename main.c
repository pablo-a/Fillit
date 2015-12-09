/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:37:23 by pabril            #+#    #+#             */
/*   Updated: 2015/12/09 17:45:31 by pabril           ###   ########.fr       */
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

//I've checke for the validity of the signs and the squares
//now I need to see if the Tetrimonis are valid as well

int		main(int argc, char **argv)
{
	int		fd;
	char	buff;
	char	buffer[BUFF_SIZE];
	int		i;
	int		nb;

	nb = 4;
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
	if (sign_checker(buffer) && all_squares(buffer) && check_valid_piece(buffer))
		printf("test!\n");
	else
	{
		ft_putendl("error");
		return (0);
	}
	int size_square = min_size_square(buffer);
	ft_putnbr(size_square);
	char *result;
	result = create_square(size_square);
	t_list *lst;
	lst = store_pieces(buffer);
	if (size_square > 3)
		resize_lst(lst, size_square, 4);
//	else
//		reduce_lst(lst, size_square, 4);
	nb  = size_square;
	while (resolution(lst, size_square, result) == 0)
	{
		size_square++;
		result = create_square(size_square);
		resize_lst(lst, size_square, nb);
		nb ++;
	}
	ft_putendl(result);
	return (0);
}
