/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:34:36 by gbadi             #+#    #+#             */
/*   Updated: 2015/03/01 15:55:46 by dvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft.h"
# include "get_next_line.h"
# include <ncurses.h>
# include <curses.h>
# include <time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
////////////////////////////
# include <stdio.h>////////
//////////////////////////

# define SIZE 			4
# define EMPTY 			3

# define COLOR_EMPTY	(3 + 10)
# define COLOR_BG		(5 + 10)
# define COLOR_2		(2 + 10)
# define COLOR_4		(4 + 10)
# define COLOR_8		(8 + 10)
# define COLOR_16		(16 + 10)
# define COLOR_32		(32 + 10)
# define COLOR_64		(64 + 10)
# define COLOR_128		(128 + 10)
# define COLOR_256		(256 + 10)
# define COLOR_512		(512 + 10)
# define COLOR_1024		(1024 + 10)
# define COLOR_2048		(2048 + 10)
# define COLOR_4098		(4098 + 10)

# define TWO_RATIO 		8

typedef struct			s_env
{
	int					**tab;
	size_t				score;
	size_t				highscore;
	char				pop;
}						t_env;

enum 					e_const
{
	WIN_VALUE = 2048
};

int						**fill_tab(t_env *env);
void					ft_draw_grid(int **tab);
int						**make_tab();
int						**move_top(t_env *env);
int						**move_bottom(t_env *env);
int						**merge_bottom(t_env *env);
int						**merge_top(t_env *env);
int						**move_left(t_env *env);
int						**merge_left(t_env *env);
int						**move_right(t_env *env);
int						**merge_right(t_env *env);
void					ft_init(void);
int						**ft_keytrigger(int keyPress, t_env *env);
int						check(t_env *env);

void	ascii_1(int y, int x);
void	print_2(int y, int x);
void	ascii_3(int y, int x);
void	print_4(int y, int x);
void	ascii_5(int y, int x);
void	ascii_6(int y, int x);
void	print_8(int y, int x);
void	ascii_9(int y, int x);
void	ascii_16(int y, int x);
void	ascii_32(int y, int x);
void	ascii_64(int y, int x);
void	ascii_128(int y, int x);
void	ascii_256(int y, int x);
void	ascii_512(int y, int x);
void	ascii_1024(int y, int x);
void	ascii_2048(int y, int x);
void	ascii_4096(int y, int x);
void					free_env(t_env *e);

#endif
