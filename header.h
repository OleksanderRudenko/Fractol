/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:49:15 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 11:51:55 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include "./libft/libft.h"
# include <math.h>
# define WIDTH 700
# define HEIGHT 700
# include <sys/types.h>

typedef struct	s_im
{
	void		*d_pic;
	char		*pic;
	int			bpp;
	int			s_l;
	int			end;
	int			color;
	float		c_re;
	float		c_im;
	float		jul_re;
	float		jul_im;

}				t_im;

typedef struct	s_frac
{
	void		*mlx;
	void		*win;
	int			iteration;
	float		zoom;
	float		move_x;
	float		move_y;
	int			num_frac;
	int			m_but3;
	t_im		*image;
}				t_frac;

void			get_image(t_frac *fr);
int				get_color(int n);
int				get_color3(int n);
int				find_mandel(float c_r, float c_im, int maxiter);
void			pixel_image(t_frac *one, int x, int y, int n);
void			pixel_image2(t_im *lol, int x, int y, int n);
void			draw_julia(t_frac *one);
void			draw_mandel(t_frac *one);
void			move_r_l(t_frac *one, float a);
void			move_d_u(t_frac *one, float a);
void			zoom(t_frac *one, float a);
void			draw_burn_ship(t_frac *one);
void			usage_er();
int				check_input(char *av, t_frac *one, int ac);
void			draw_tricorn(t_frac *one);
int				mouse_hook(int key, int x, int y, t_frac *one);
void			iter(t_frac *one, int a);
void			draw_string_menu(t_frac *one);
int				key_hook(int key, t_frac *one);
void			draw_mandel_c(t_frac *one);
int				check_ac_three(char *av, t_frac *one, int ac);
void			basic_check(char *av);

#endif
