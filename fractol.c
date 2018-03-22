/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:27:40 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 12:51:09 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			key_hook(int key, t_frac *one)
{
	if (key == 1)
		one->m_but3 = 1;
	if (key == 2)
		one->m_but3 = 0;
	if (key == 53)
		exit(0);
	if (key == 124 || key == 123)
		move_r_l(one, key == 123 ? 0.1 : -0.1);
	if (key == 125 || key == 126)
		move_d_u(one, key == 126 ? 0.1 : -0.1);
	if (key == 69 || key == 78)
		zoom(one, key == 69 ? 1.01 : 0.99);
	if (key == 67 || key == 75)
		iter(one, key == 67 ? 10 : -10);
	return (0);
}

void		get_image(t_frac *one)
{
	one->image = (t_im *)malloc(sizeof(t_im));
	one->image->d_pic = mlx_new_image(one->mlx, WIDTH, HEIGHT);
	one->image->pic = mlx_get_data_addr(one->image->d_pic, &one->image->bpp,\
		&one->image->s_l, &one->image->end);
	one->image->bpp /= 8;
	one->iteration = 90;
	one->m_but3 = 0;
	one->zoom = 2.5;
	one->move_x = 0.0;
	one->move_y = 0.0;
	one->image->jul_re = -0.835;
	one->image->jul_im = 0.2321;
	one->image->color = mlx_get_color_value(one->mlx, 0xffff);
}

int			mouse_julia(int x, int y, t_frac *one)
{
	if (x > 0 && x < WIDTH && y > 0 && y < WIDTH && one->mlx != NULL &&\
		one->num_frac == 2 && one->m_but3 == 0)
	{
		one->image->jul_re = -fabs((float)(x - WIDTH / 2) / WIDTH) - 0.4f;
		one->image->jul_im = -fabs((float)(y - HEIGHT / 2) / HEIGHT) - 0.04f;
		draw_julia(one);
	}
	return (1);
}

void		initt(t_frac *one)
{
	one->mlx = mlx_init(one);
	get_image(one);
}

int			main(int ac, char **av)
{
	t_frac		one;
	pid_t		pid;

	ac == 2 ? basic_check(av[1]) : 0;
	if (ac == 3)
	{
		basic_check(av[1]);
		basic_check(av[2]);
	}
	pid = ac == 3 ? fork() : 0;
	initt(&one);
	one.win = mlx_new_window(one.mlx, WIDTH, HEIGHT, "FRACT_OL");
	if (pid == 0 && ac == 3)
		check_ac_three(av[1], &one, ac);
	else if (pid > 0 && ac == 3)
		check_ac_three(av[2], &one, ac);
	else if (ac == 2)
		check_input(av[1], &one, ac);
	else
		usage_er();
	mlx_mouse_hook(one.win, mouse_hook, &one);
	mlx_hook(one.win, 2, 5, key_hook, &one);
	mlx_hook(one.win, 6, 1L << 6, mouse_julia, &one);
	mlx_loop(one.mlx);
	return (0);
}
