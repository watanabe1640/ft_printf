/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:58:57 by taikwata          #+#    #+#             */
/*   Updated: 2024/09/28 11:28:22 by taikwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long long n, int is_upper)
{
	char	*hex;

	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16, is_upper);
		ft_putchar(hex[n % 16]);
	}
	else
		ft_putchar(hex[n]);
	return (count_hex(n));
}
