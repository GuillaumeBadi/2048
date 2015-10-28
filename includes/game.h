/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:34:36 by dvolberg          #+#    #+#             */
/*   Updated: 2015/03/03 15:51:06 by bsautron         ###   ########.fr       */
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

# define EMPTY			3
# define COLOR_EMPTY	(13)
# define COLOR_BG		(15)
# define COLOR_2		(31)
# define COLOR_4		(32)
# define COLOR_8		(33)
# define COLOR_16		(34)
# define COLOR_32		(35)
# define COLOR_64		(36)
# define COLOR_128		(37)
# define COLOR_256		(38)
# define COLOR_512		(39)
# define COLOR_1024		(40)
# define COLOR_2048		(41)
# define COLOR_4096		(42)
# define TWO_RATIO 		8

typedef struct			s_env
{
	int					**tab;
	int					win;
	int					ret;
	int					ch;
	size_t				score;
	size_t				highscore;
	char				pop;
	int					y;
	int					x;
	int					y_new;
	int					x_new;
	int					y_max;
	int					x_max;
	int					status;
}						t_env;

enum					e_const
{
	SIZE = 4,
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
int						**ft_keytrigger(int key_press, t_env *env);
int						check(t_env *env);
void					ft_putnbr_to_grid(int y_max, int x_max, int **tab);
int						ft_print_tout(int val, int x, int y);
void					gameover(void);
int						ft_get_pair(int val);
void					printtitle();
void					print_2(int y, int x);
void					print_8(int y, int x);
void					print_4(int y, int x);
void					ascii_0(int y, int x);
void					ascii_1(int y, int x);
void					ascii_2(int y, int x);
void					ascii_3(int y, int x);
void					ascii_4(int y, int x);
void					ascii_5(int y, int x);
void					ascii_6(int y, int x);
void					ascii_8(int y, int x);
void					ascii_9(int y, int x);
void					ascii_16(int y, int x);
void					ascii_32(int y, int x);
void					ascii_64(int y, int x);
void					ascii_128(int y, int x);
void					ascii_256(int y, int x);
void					ascii_512(int y, int x);
void					ascii_1024(int y, int x);
void					ascii_2048(int y, int x);
void					ascii_4096(int y, int x);
void					free_env(t_env *e);
int						play(t_env *env);
void					printwin(void);

#endif
