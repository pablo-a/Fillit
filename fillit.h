/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:57:49 by pabril            #+#    #+#             */
/*   Updated: 2015/12/11 16:33:11 by pabril           ###   ########.fr       */
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

int		all_squares(char *str);
int		sign_checker(char *str);
int		read_file(char *buffer, int argc, char **argv);

int		check_number_pieces(char *str, int index);
int		count_neighbours(int count, char *str, int index, int i);
int		check_shape(char *str, int index);
int		check_valid_piece(char *str);

int		number_pieces(char *str);
int		min_size_square(char *str);

int		resize_lst(t_list *lst, int size_square, int nb);
int		reduce_lst(t_list *lst, int size_square);
int		can_reduce(t_list *lst, int size_square);
int		column_and_line_empty(char *str);
char	*reduce(t_list *lst, int size_square);

t_list	*store_pieces(char *str);
void	identify_piece(t_list **lst);
int		empty_left_and_top(char *str);
char	*replace_piece(char *str, int cas);
void	place_piece(t_list **lst);

char	*create_square(int size);
int		can_place(t_list *lst, int index, char *result, int size_square);
void	place(t_list *lst, char **result, int index, int size_square);
void	unplace_piece(t_list *lst, char **result);
int		resolution(t_list *lst, int size_square, char *result);

#endif
