/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:09:57 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 12:16:42 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		move_r_l(t_frac *one, float a)
{
	ft_bzero(one->image->pic, WIDTH * WIDTH * one->image->bpp);
	one->move_x += a / one->zoom;
	if (one->num_frac == 1)
		draw_mandel(one);
	if (one->num_frac == 2)
		draw_julia(one);
	if (one->num_frac == 3)
		draw_burn_ship(one);
	if (one->num_frac == 4)
		draw_tricorn(one);
	if (one->num_frac == 5)
		draw_mandel_c(one);
}

void		move_d_u(t_frac *one, float a)
{
	ft_bzero(one->image->pic, WIDTH * WIDTH * one->image->bpp);
	one->move_y += a / one->zoom;
	if (one->num_frac == 1)
		draw_mandel(one);
	if (one->num_frac == 2)
		draw_julia(one);
	if (one->num_frac == 3)
		draw_burn_ship(one);
	if (one->num_frac == 4)
		draw_tricorn(one);
	if (one->num_frac == 5)
		draw_mandel_c(one);
}

void		zoom(t_frac *one, float a)
{
	ft_bzero(one->image->pic, WIDTH * WIDTH * one->image->bpp);
	if (one->zoom > 0.05)
	{
		one->zoom *= a;
		if (one->num_frac == 1)
			draw_mandel(one);
		if (one->num_frac == 2)
			draw_julia(one);
		if (one->num_frac == 3)
			draw_burn_ship(one);
		if (one->num_frac == 4)
			draw_tricorn(one);
		if (one->num_frac == 5)
			draw_mandel_c(one);
	}
	else
	{
		if (one->zoom < 0.05)
		{
			one->zoom *= 1.01;
			one->move_x = 0;
			one->move_y = 0;
		}
	}
}

void		iter(t_frac *one, int a)
{
	ft_bzero(one->image->pic, WIDTH * WIDTH * one->image->bpp);
	if (one->iteration > 10 && one->iteration < 5000)
	{
		one->iteration += a;
		if (one->num_frac == 1)
			draw_mandel(one);
		if (one->num_frac == 2)
			draw_julia(one);
		if (one->num_frac == 3)
			draw_burn_ship(one);
		if (one->num_frac == 4)
			draw_tricorn(one);
		if (one->num_frac == 5)
			draw_mandel_c(one);
	}
	else
	{
		if (one->iteration <= 10)
			one->iteration += 10;
		else
			one->iteration -= 10;
	}
}

int			mouse_hook(int key, int x, int y, t_frac *one)
{
	float	new_x;
	float	new_y;

	if (key == 1)
		one->m_but3 = 1;
	if (key == 2)
		one->m_but3 = 0;
	if (key == 4)
	{
		zoom(one, 1.1);
		new_x = (((float)(WIDTH / 2) - x) / (WIDTH * one->zoom));
		new_y = (((float)(HEIGHT / 2) - y) / (HEIGHT * one->zoom));
		one->move_x -= new_x;
		one->move_y -= new_y;
	}
	if (key == 5)
	{
		zoom(one, 0.9);
		new_x = (((float)(WIDTH / 2) - x) / (WIDTH * one->zoom));
		new_y = (((float)(HEIGHT / 2) - y) / (HEIGHT * one->zoom));
		one->move_x -= new_x;
		one->move_y -= new_y;
	}
	return (0);
}
