/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:29:11 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 12:33:21 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	usage_er(void)
{
	ft_putendl("usage: ./fractol [fractal name]");
	ft_putendl("Here is some possible fractals:");
	ft_putendl("mandelbrot");
	ft_putendl("julia");
	ft_putendl("burning ship");
	ft_putendl("tricorn");
	ft_putendl("mandel_2");
	ft_putstr("or u can type 2 types of fractols: ");
	ft_putendl("./fractol [fractal name] [fractal name]");
	exit(0);
}

void	basic_check(char *av)
{
	if (ft_strcmp(av, "mandelbrot") != 0 && ft_strcmp(av, "julia") != 0 &&\
		ft_strcmp(av, "burning ship") != 0 && ft_strcmp(av, "tricorn") != 0 &&\
		ft_strcmp(av, "mandel_2") != 0)
		usage_er();
}

int		check_input(char *av, t_frac *one, int ac)
{
	if (ac != 2)
		usage_er();
	if (ft_strcmp(av, "mandelbrot") == 0)
		draw_mandel(one);
	else if (ft_strcmp(av, "julia") == 0)
		draw_julia(one);
	else if (ft_strcmp(av, "burning ship") == 0)
		draw_burn_ship(one);
	else if (ft_strcmp(av, "tricorn") == 0)
		draw_tricorn(one);
	else if (ft_strcmp(av, "mandel_2") == 0)
		draw_mandel_c(one);
	else
		usage_er();
	return (0);
}

int		check_ac_three(char *av, t_frac *one, int ac)
{
	if (ac != 3)
		usage_er();
	if (ft_strcmp(av, "mandelbrot") == 0)
		draw_mandel(one);
	else if (ft_strcmp(av, "julia") == 0)
		draw_julia(one);
	else if (ft_strcmp(av, "burning ship") == 0)
		draw_burn_ship(one);
	else if (ft_strcmp(av, "tricorn") == 0)
		draw_tricorn(one);
	else if (ft_strcmp(av, "mandel_2") == 0)
		draw_mandel_c(one);
	else
		usage_er();
	return (0);
}

void	draw_string_menu(t_frac *one)
{
	mlx_string_put(one->mlx, one->win, 10, 5, 0xffffff, "MENU");
	mlx_string_put(one->mlx, one->win, 10, 25, 0xBB55AA, "+ / - zoom");
	mlx_string_put(one->mlx, one->win, 10, 50, 0xFFC832, "Mouse wheel - zoom");
	mlx_string_put(one->mlx, one->win, 10, 75, 0xFFC832, "Arrow keys for move");
	mlx_string_put(one->mlx, one->win, 10, 100, 0xFFC832, "/ * iterations +/-");
}
