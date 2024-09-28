/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:57:13 by taikwata          #+#    #+#             */
/*   Updated: 2024/09/28 11:28:18 by taikwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		len++;
	}
	ft_putchar(n % 10 + '0');
	return (len + 1);
}

// #include <stdio.h>
// int main()
// {
// 	ft_putnbr(-2147483648);
// 	printf("\n %d\n", ft_putnbr(21));
// 	printf("\n %d\n", ft_putnbr(-21));
// 	return 0;
// }
