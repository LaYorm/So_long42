/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:41:39 by yorimek           #+#    #+#             */
/*   Updated: 2025/12/12 13:07:20 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_valid(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_is_param(str[i + 1]))
		{
			return (1);
		}
		if (str[i] == '%' && str[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	return (0);
}

int	ft_is_param(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int	ft_write_arg(char c, va_list args, int len_tot)
{
	int	if_ptr;

	if_ptr = 0;
	if (c == 'c')
		len_tot = ft_putchar_count((char)va_arg(args, int), len_tot);
	else if (c == 's')
		len_tot = ft_putstr_count(va_arg(args, char *), len_tot);
	else if (c == 'p')
	{
		if_ptr = 1;
		len_tot = ft_put_adress((uintptr_t)va_arg(args, void *), len_tot,
				if_ptr);
	}
	else if (c == 'd' || c == 'i')
		len_tot = ft_putnbr_count(va_arg(args, int), len_tot);
	else if (c == 'u')
		len_tot = ft_put_unsigned(va_arg(args, unsigned int), len_tot);
	else if (c == 'x')
		len_tot = ft_puthexa_lower(va_arg(args, unsigned int), len_tot);
	else if (c == 'X')
		len_tot = ft_puthexa_upper(va_arg(args, unsigned int), len_tot);
	else if (c == '%')
		len_tot = ft_putchar_count('%', len_tot);
	return (len_tot);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len_tot;

	i = 0;
	len_tot = 0;
	if (!str)
		return (-1);
	if (ft_check_valid(str))
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!ft_is_param(str[i]))
				len_tot = ft_write_arg(str[i], args, len_tot);
		}
		else
			len_tot = ft_putchar_count(str[i], len_tot);
		i++;
	}
	va_end(args);
	return (len_tot);
}
