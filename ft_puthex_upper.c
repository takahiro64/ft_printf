/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:56:40 by thine             #+#    #+#             */
/*   Updated: 2024/07/15 15:21:24 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_puthex_upper(unsigned long long num, int *count)
{
	if (num >= 16)
	{
		ft_puthex_upper(num / 16, count);
		*count += ft_putchr("0123456789ABCDEF"[num % 16]);
	}
	else
	{
		*count += ft_putchr("0123456789ABCDEF"[num % 16]);
	}
	return (*count);
}
