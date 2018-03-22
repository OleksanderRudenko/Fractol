/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:48:53 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 13:02:01 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pixel_image(t_frac *one, int x, int y, int n)
{
	int			r;
	int			g;
	int			b;

	r = 0xFF0000;
	g = 0x00FF00;
	b = 0x0000FF;
	one->image->pic[(y * 700 + x) * 4] = r * 3 * n / one->iteration;
	one->image->pic[(y * 700 + x) * 4 + 1] = g * 6 * n / one->iteration;
	one->image->pic[(y * 700 + x) * 4 + 2] = b * 9 * n / one->iteration;
}

void	pixel_image2(t_im *lol, int x, int y, int n)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (lol->color & 0xFF0000) >> 16;
	g = (lol->color & 0xFF00) >> 8;
	b = (lol->color & 0xFF);
	lol->pic[(y * 700 + x) * 4] = r * 5 * sin(3.1415 / 180 * n);
	lol->pic[(y * 700 + x) * 4 + 1] = g * sin(3.1415 / 180 * n);
	lol->pic[(y * 700 + x) * 4 + 2] = b * 2 * sin(3.1415 / 180 * n);
}
