/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:37:23 by pabril            #+#    #+#             */
/*   Updated: 2015/12/08 15:29:50 by pabril           ###   ########.fr       */
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
	if (sign_checker(buffer) == 1 && printf("ok1\n"))
		if (all_squares(buffer) == 1 && printf("ok2\n"))
			if (check_valid_piece(buffer) == 1 && printf("ok3\n"))
				printf("test!\n");

	int size_square = min_size_square(buffer);
	char *result;
	result = create_square(size_square);
	ft_putendl(result);
	t_list *lst;
	lst = store_pieces(buffer);
	resolution(lst, size_square, result);
	return (0);
}
