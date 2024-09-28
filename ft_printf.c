/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:28:19 by taikwata          #+#    #+#             */
/*   Updated: 2024/09/28 11:29:01 by taikwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	format_handler(char format_type, va_list args)
{
	if (format_type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format_type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format_type == 'd' || format_type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format_type == 'p')
		return (ft_putptr(va_arg(args, unsigned long long)));
	else if (format_type == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format_type == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (format_type == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (format_type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_len;
	size_t	i;

	if (!format)
		return (-1);
	printed_len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed_len += format_handler(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			printed_len++;
		}
		i++;
	}
	va_end(args);
	return (printed_len);
}

// #include <stdio.h>
// int main()
// {
// 	int one		= ft_printf("Hello, %c %c\n", 'A', 'B');
// 	int one_de	= printf("Hello, %c %c\n", 'A', 'B');
// 	// char str = 0;
// 	printf("one: %d  one de: %d\n", one, one_de);
// 	ft_printf("Hello, %s\n", "Abc");
// 	printf("Hello, %s\n", "Abc");
// 	ft_printf("Hello, %d\n", 100);
// 	printf("Hello, %d\n", 100);
// 	printf("one point length %d \n",printf("%p\n", &one));
// 	printf("one point length %d \n",ft_printf("%p\n", &one));
// 	printf("%p\n", NULL);
// 	ft_printf("%p\n", NULL);
// 	unsigned int n = 100;
// 	unsigned int nm = -100;
// 	printf("%u\n",n);
// 	ft_printf("%u\n",n);
// 	printf("%u\n",nm);
// 	ft_printf("%u\n",nm);

// 	printf("print hex \n");
// 	printf("%d\n",printf("%x\n",1000));
// 	printf("%d\n",ft_printf("%x\n",1000));

// 	printf("print HEX \n");
// 	printf("%d\n",printf("%X\n",-1));
// 	printf("%d\n",ft_printf("%X\n",-1));
// 	return 0;
// }
// // cc -Wall -Wextra -Werror ft_printf.c ft_putchar.c \
// ft_putstr.c ft_putnbr.c ft_strlen.c && ./a.out