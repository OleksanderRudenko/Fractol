/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:08:03 by arudenko          #+#    #+#             */
/*   Updated: 2018/01/15 11:00:17 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	char	*hex;
	int		i;
	int		n;

	hex = "0123456789ABCDEF";
	n = value;
	i = 1;
	while (n /= base)
		i++;
	if (value < 0 && base == 10)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = 48;
	s[i] = '\0';
	while (value)
	{
		s[--i] = hex[value < 0 ? -(value % base) : value % base];
		value /= base;
	}
	return (s);
}
