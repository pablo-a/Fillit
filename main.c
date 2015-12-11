/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:37:23 by pabril            #+#    #+#             */
/*   Updated: 2015/12/11 17:39:52 by pabril           ###   ########.fr       */
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

int		sign_checker(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

int		read_file(char *buffer, int argc, char **argv)
{
	int		fd;
	char	buff;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buff, 1) != 0 && buff != '\0')
	{
		buffer[i] = buff;
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	buffer[BUFF_SIZE];
	int		size_square;
	char	*result;
	t_list	*lst;

	if (read_file(buffer, argc, argv) == 0)
		return (0);
	if (!sign_checker(buffer) || !all_squares(buffer)
			|| !check_valid_piece(buffer))
	{
		ft_putendl("error");
		return (0);
	}
	size_square = min_size_square(buffer);
	lst = store_pieces(buffer);
	while (resize_lst(lst, size_square, 4) == 0)
		size_square++;
	result = create_square(size_square);
	while (resolution(lst, size_square, result) == 0)
	{
		size_square++;
		result = create_square(size_square);
		resize_lst(lst, size_square, size_square - 1);
	}
	ft_putstr(result);
	return (0);
}
