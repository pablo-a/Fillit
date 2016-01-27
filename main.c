/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:37:23 by pabril            #+#    #+#             */
/*   Updated: 2016/01/27 10:14:17 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		all_squares(char *str)
{
	int block;
	int sign;

	sign = 0;
	block = 0;
	while (*str != '\0')
	{
		if (*str == '.' || *str == '#')
		{
			sign++;
			block++;
		}
		if (*str == '\n' & sign != 4 & block != 16)
			return (0);
		if (*str == '\n' && sign == 4)
			sign = 0;
		if (*str == '\n' && *(str - 1) == '\n' && block == 16)
			block = 0;
		if (sign > 4 || block > 16)
			return (0);
		str++;
	}
	if (block != 16)
		return (0);
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
	{
		ft_putendl("error");
		return (0);
	}
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
	if (!sign_checker(buffer) || !all_squares(buffer) || !check_piece(buffer))
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
