/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:44:50 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 12:01:28 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_mandel(float c_r, float c_im, int maxiter)
{
	int		i;
	float	z_re;
	float	z_im;
	float	next_z_im;
	float	next_z_re;

	next_z_im = 0;
	next_z_re = 0;
	i = 0;
	while (i < maxiter && (next_z_re * next_z_re + next_z_im * next_z_im) < 4.0)
	{
		z_im = next_z_im;
		z_re = next_z_re;
		next_z_im = 2 * z_re * z_im + c_im;
		next_z_re = z_re * z_re - z_im * z_im + c_r;
		i++;
	}
	return (i);
}

void	draw_mandel(t_frac *one)
{
	int		x;
	int		y;
	int		n;

	one->num_frac = 1;
	x = 0;
	while (x < HEIGHT)
	{
		one->image->c_re = (x - WIDTH / 2) /\
			(0.1 * one->zoom * WIDTH) + one->move_x;
		y = 0;
		while (y < WIDTH)
		{
			one->image->c_im = (y - HEIGHT / 2) /\
				(0.1 * one->zoom * HEIGHT) + one->move_y;
			n = find_mandel(one->image->c_re, one->image->c_im, one->iteration);
			one->image->color = get_color(n);
			pixel_image2(one->image, x, y, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(one->mlx, one->win, one->image->d_pic, 0, 0);
	draw_string_menu(one);
}

int		find_mandel_c(float c_r, float c_im, int maxiter)
{
	int		i;
	float	temp;

	i = 0;
	while (i < maxiter && (c_r * c_r + c_im * c_im) < 4.0)
	{
		temp = -(c_r * c_r - 2 * c_im * c_im) * (c_r) + c_r;
		c_im = (2 * c_r * c_r - c_im * c_im) * (c_im) + c_im;
		c_r = temp;
		i++;
	}
	return (i);
}

void	draw_mandel_c(t_frac *one)
{
	int		x;
	int		y;
	int		n;

	one->num_frac = 5;
	x = 0;
	while (x < HEIGHT)
	{
		one->image->c_re = (x - WIDTH / 2) /\
			(0.1 * one->zoom * WIDTH) + one->move_x;
		y = 0;
		while (y < WIDTH)
		{
			one->image->c_im = (y - HEIGHT / 2) /\
				(0.1 * one->zoom * HEIGHT) + one->move_y;
			n = find_mandel_c(one->image->c_re,\
				one->image->c_im, one->iteration);
			one->image->color = get_color(n);
			pixel_image2(one->image, x, y, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(one->mlx, one->win, one->image->d_pic, 0, 0);
	draw_string_menu(one);
}
