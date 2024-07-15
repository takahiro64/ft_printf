/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:55:31 by thine             #+#    #+#             */
/*   Updated: 2024/07/15 15:22:01 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putpointa(void *p)
{
	int	res;

	ft_putstr("0x");
	res = 2;
	res = ft_puthex_lower((unsigned long long)p, &res);
	return (res);
}
