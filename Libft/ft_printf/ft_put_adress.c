/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:22:40 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/20 16:01:22 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_adress(uintptr_t n, int len_tot, int if_ptr)
{
	if (!n && if_ptr)
	{
		len_tot = ft_putstr_count("(nil)", len_tot);
		if_ptr = 0;
		return (len_tot);
	}
	if (if_ptr)
	{
		len_tot = ft_putstr_count("0x", len_tot);
		if_ptr = 0;
	}
	if (n > 15)
	{
		len_tot = ft_put_adress((n / 16), len_tot, if_ptr);
		len_tot = ft_put_adress((n % 16), len_tot, if_ptr);
	}
	else if (n < 10)
		len_tot = ft_putchar_count((n + '0'), len_tot);
	else
		len_tot = ft_putchar_count((char)n - 10 + 'a', len_tot);
	return (len_tot);
}
