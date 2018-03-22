/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:33:47 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 18:57:36 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_burn_ship(float c_r, float c_im, int maxiter)
{
	int		i;
	float	temp;
	float	x;
	float	y;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (i < maxiter && (x * x + y * y) < 4.0)
	{
		temp = x * x - y * y - c_r;
		y = fabs(2 * x * y + c_im);
		x = fabs(temp);
		i++;
	}
	return (i);
}

void	draw_burn_ship(t_frac *one)
{
	int		x;
	int		y;
	int		n;

	one->num_frac = 3;
	x = 0;
	while (x < HEIGHT)
	{
		one->image->c_re = (x - WIDTH / 2) / (0.1 * one->zoom * WIDTH) + one->move_x;
		y = 0;
		while (y < WIDTH)
		{
			one->image->c_im = (y - HEIGHT / 2) /\
				(0.1 * one->zoom * HEIGHT) + one->move_y;
			n = find_burn_ship(one->image->c_re,\
				one->image->c_im, one->iteration);
			one->image->color = get_color(n);
			pixel_image(one, x, y, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(one->mlx, one->win, one->image->d_pic, 0, 0);
	draw_string_menu(one);
}
