/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:50:19 by thine             #+#    #+#             */
/*   Updated: 2024/07/04 20:13:19 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include"printf.h"
#include <stdarg.h>
#include <unistd.h>
static void	ft_putnbr(int n);
static void	ft_putHex_upper(unsigned long long num);
static void	ft_putHex_lower(unsigned long long num);
static void	ft_putpointa(void *p);
static void	ft_putstr(char *s);
static void	ft_putchr(int c);
static int	print_arg(char str, va_list ap);

void	ft_printf(char *arg, ...)
{
	va_list	ap;
	char	*str;

	str = arg;
	va_start(ap, arg);
	while (*str)
	{
		if (*str == '%')
			print_arg(*++str, ap);
		else
			write(1, str, 1);
		str++;
	}
	va_end(ap);
}

static int	print_arg(char str, va_list ap)
{
	if (str == 'c')
		ft_putchr(va_arg(ap, int));
	else if (str == 's')
		ft_putstr(va_arg(ap, char *));
	else if (str == 'p')
		ft_putpointa(va_arg(ap, void *));
	else if (str == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (str == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	else if (str == 'x')
		ft_putHex_lower(va_arg(ap, unsigned long long));
	else if (str == 'X')
		ft_putHex_upper(va_arg(ap, unsigned long long));
	else if (str == '%')
		ft_putchr('%');
	return (1);
}

static void	ft_putchr(int c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *s)
{
	while (*s)
		ft_putchr(*s++);
}

static void	ft_putpointa(void *p)
{
	ft_putstr("0x");
	ft_putHex_lower((unsigned long long)p);
}

static void	ft_putHex_upper(unsigned long long num)
{
	if (num > 16)
	{
		ft_putHex_upper(num / 16);
		ft_putchr("0123456789ABCDEF"[num % 16]);
	}
	else
	{
		ft_putchr("0123456789ABCDEF"[num % 16]);
	}
}

static void	ft_putHex_lower(unsigned long long num)
{
	if (num > 16)
	{
		ft_putHex_lower(num / 16);
		ft_putchr("0123456789abcdef"[num % 16]);
	}
	else
	{
		ft_putchr("0123456789abcdef"[num % 16]);
	}
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchr('-');
		n = -n;
	}
	if (n < 10)
		ft_putchr(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchr(n % 10 + '0');
	}
}
