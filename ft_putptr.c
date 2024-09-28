/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:59:00 by taikwata          #+#    #+#             */
/*   Updated: 2024/09/28 11:28:14 by taikwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_pointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

int	ft_write_ptr(unsigned long long ptr)
{
	if (ptr > 16)
	{
		ft_write_ptr(ptr / 16);
		ft_putchar("0123456789abcdef"[ptr % 16]);
	}
	else
		ft_putchar("0123456789abcdef"[ptr % 16]);
	return (ft_count_pointer(ptr));
}

int	ft_putptr(unsigned long long ptr)
{
	int	printed_len;

	if (!ptr)
		return (ft_putstr("0x0"));
	printed_len = 0;
	printed_len += ft_putstr("0x");
	printed_len += ft_write_ptr((unsigned long long)ptr);
	return (printed_len);
}

// #include <stdio.h>
// int main()
// {
// 	ft_putptr((unsigned long long)"");
// 	printf("\n");
// 	printf("%p",(unsigned long long)"");

// 	printf("\n");
// 	ft_putptr((unsigned long long)"aa");
// 	printf("\n");
// 	printf("%p",(unsigned long long)"aa");
// }