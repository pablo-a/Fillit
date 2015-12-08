/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:57:49 by pabril            #+#    #+#             */
/*   Updated: 2015/12/08 12:53:16 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 1024

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

int		all_squares(char *str);//							 functions of
int		sign_checker(char *str);//								main.c

int		check_number_pieces(char *str, int index);//
int		count_neighbours(int count, char *str, int index, int i);// functions of
int		check_shape(char *str, int index);//					check_valid_pieces.c
int		check_valid_piece(char *str);//

int		number_pieces(char *str);//				functions of
int		min_size_square(char *str);//			min_size_square.c

t_list	*store_pieces(char *str);//				function of store_pieces.c
void	identify_piece(t_list **lst);

char	*create_square(int size);//									functions of
int		can_place(t_list *lst, int index, char *result);
void	place(t_list *lst, char **result, int index);
void	unplace_piece(t_list *lst, char **result);
int		resolution(t_list *lst, int size_square, char *result);//	resolution.c

#endif
