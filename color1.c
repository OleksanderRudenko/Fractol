/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:04:05 by arudenko          #+#    #+#             */
/*   Updated: 2018/02/05 12:07:57 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_color3(int n)
{
	if (n <= 2 && n >= 0)
		return (0x000000);
	if (n < 5 && n > 2)
		return (0x83d0c9);
	if (n < 20 && n >= 5)
		return (0x65c3ba);
	if (n < 30 && n >= 20)
		return (0x54b2a9);
	if (n < 40 && n >= 30)
		return (0x35a79c);
	if (n < 50 && n >= 40)
		return (0x009688);
	if (n < 60 && n >= 50)
		return (0x006666);
	if (n < 70 && n >= 60)
		return (0x005555);
	if (n < 80 && n >= 70)
		return (0x004444);
	if (n <= 90 && n >= 70)
		return (0x003333);
	return (0xFFFFFF);
}

int		get_color(int n)
{
	if (n <= 2 && n >= 0)
		return (0x000000);
	if (n < 5 && n > 2)
		return (0x8d58ff);
	if (n < 20 && n >= 5)
		return (0x6f00d7);
	if (n < 30 && n >= 20)
		return (0x440084);
	if (n < 40 && n >= 30)
		return (0x6f37ab);
	if (n < 50 && n >= 40)
		return (0x4c1a81);
	if (n < 60 && n >= 50)
		return (0x330b5e);
	if (n < 70 && n >= 60)
		return (0x130027);
	if (n <= 90 && n >= 70)
		return (0x000000);
	return (0xFFFFFF);
}
