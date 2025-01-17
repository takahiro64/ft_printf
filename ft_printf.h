/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thine <thine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:53:09 by thine             #+#    #+#             */
/*   Updated: 2024/07/15 15:21:31 by thine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);
int	ft_putnbr(long long int n, int *count);
int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_putpointa(void *p);
int	ft_puthex_upper(unsigned long long num, int *count);
int	ft_puthex_lower(unsigned long long num, int *count);

#endif
