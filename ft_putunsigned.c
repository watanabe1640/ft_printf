/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:35:02 by taikwata          #+#    #+#             */
/*   Updated: 2024/09/28 11:28:05 by taikwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_write_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_write_unsigned(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar(n % 10 + '0');
	}
	return (ft_count_unsigned(n));
}

int	ft_putunsigned(unsigned int n)
{
	int	printed_len;

	if (n < 0)
		return (0);
	printed_len = 0;
	printed_len += ft_write_unsigned(n);
	return (printed_len);
}
