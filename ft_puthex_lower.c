/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:57:39 by thine             #+#    #+#             */
/*   Updated: 2024/07/15 15:21:26 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_puthex_lower(unsigned long long num, int *count)
{
	if (num >= 16)
	{
		ft_puthex_lower(num / 16, count);
		*count += ft_putchr("0123456789abcdef"[num % 16]);
	}
	else
	{
		*count += ft_putchr("0123456789abcdef"[num % 16]);
	}
	return (*count);
}
