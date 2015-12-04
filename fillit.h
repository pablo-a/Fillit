/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:57:49 by pabril            #+#    #+#             */
/*   Updated: 2015/12/04 13:29:37 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 90622

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_piece
{
	char			*piece;
	struct s_piece	*next;
}				t_piece;

int				check_valid_piece(char *str);
int				sign_checker(char *str);
int				check_shape(char *str, int index);
int				check_number_pieces(char *str, int index);
int				all_squares(char *str);
int				min_size_square(char *str);

#endif
