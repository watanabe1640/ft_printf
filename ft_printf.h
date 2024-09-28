/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:35:12 by taikwata          #+#    #+#             */
/*   Updated: 2024/09/28 11:33:49 by taikwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
size_t	ft_strlen(char *str);
int		ft_putptr(unsigned long long ptr);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long long n, int is_upper);

#endif