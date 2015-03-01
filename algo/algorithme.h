/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <gbadi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:30:30 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 01:18:31 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHME_H

# define ALGORITHME_H

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define SIZE 			4
# define EMPTY 			3
# define TWO_RATIO 		8

typedef struct			s_env
{
	int					**tab;
	size_t				score;
	size_t				highscore;
}						t_env;

enum 					e_const
{
	WIN_VALUE = 2048
};

int						**fill_tab(int **tab);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>;
void					print_tab(int **tab);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>;
int						**make_tab();
int						**move_top(int **tab);
int						**move_bottom(int **tab);
int						**merge_bottom(int **tab);
int						**merge_top(int **tab);
int						**move_left(int **tab);
int						**merge_left(int **tab);
int						**move_right(int **tab);
int						**merge_right(int **tab);

#endif
