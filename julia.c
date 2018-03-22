/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:39:02 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 12:48:33 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_julia(float c_r, float c_im, int maxiter, t_frac *one)
{
	int		i;
	float	temp;

	i = 0;
	while (i < maxiter && (c_r * c_r + c_im * c_im) < 4.0)
	{
		temp = c_r * c_r - c_im * c_im + one->image->jul_re;
		c_im = 2 * c_r * c_im + one->image->jul_im;
		c_r = temp;
		i++;
	}
	return (i);
}

void	draw_julia(t_frac *one)
{
	int		x;
	int		y;
	int		n;

	one->num_frac = 2;
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
			n = find_julia(one->image->c_re, one->image->c_im,\
				one->iteration, one);
			one->image->color = get_color3(n);
			pixel_image(one, x, y, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(one->mlx, one->win, one->image->d_pic, 0, 0);
	draw_string_menu(one);
}

int		find_tricorn(float c_r, float c_im, int maxiter)
{
	int		i;
	float	temp;

	i = 0;
	while (i < maxiter && (c_r * c_r + c_im * c_im) < 4.0)
	{
		temp = c_r * c_r - c_im * c_im + c_r;
		c_im = -2 * c_r * c_im + c_im;
		c_r = temp;
		i++;
	}
	return (i);
}

void	draw_tricorn(t_frac *one)
{
	int		x;
	int		y;
	int		n;

	one->num_frac = 4;
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
			n = find_tricorn(one->image->c_re, one->image->c_im,\
				one->iteration);
			one->image->color = get_color3(n);
			pixel_image(one, x, y, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(one->mlx, one->win, one->image->d_pic, 0, 0);
	draw_string_menu(one);
}
