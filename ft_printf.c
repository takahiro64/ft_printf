/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:50:19 by thine             #+#    #+#             */
/*   Updated: 2024/07/15 15:21:51 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include <unistd.h>

static int	print_arg(char str, va_list ap);

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, arg);
	while (*arg)
	{
		if (*arg == '%')
			count += print_arg(*++arg, ap);
		else
		{
			write(1, arg, 1);
			count++;
		}
		arg++;
	}
	va_end(ap);
	return (count);
}

static int	print_arg(char str, va_list ap)
{
	int	count;

	count = 0;
	if (str == 'c')
		return (ft_putchr(va_arg(ap, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str == 'p')
		return (ft_putpointa(va_arg(ap, void *)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr(va_arg(ap, int), &count));
	else if (str == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int), &count));
	else if (str == 'x')
		return (ft_puthex_lower(va_arg(ap, unsigned int), &count));
	else if (str == 'X')
		return (ft_puthex_upper(va_arg(ap, unsigned int), &count));
	else if (str == '%')
		return (ft_putchr('%'));
	return (1);
}
