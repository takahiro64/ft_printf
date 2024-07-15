/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:52:11 by thine             #+#    #+#             */
/*   Updated: 2024/07/15 12:47:41 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(long long int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		*count += ft_putchr('-');
		n = -n;
	}
	if (n < 10)
		*count += ft_putchr(n + '0');
	else
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchr(n % 10 + '0');
	}
	return (*count);
}
