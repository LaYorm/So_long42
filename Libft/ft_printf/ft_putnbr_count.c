/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:13 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/20 15:54:41 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_count(int n, int len_tot)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		len_tot = ft_putchar_count('-', len_tot);
		nbr *= (-1);
	}
	if (nbr < 10)
		len_tot = ft_putchar_count((nbr + '0'), len_tot);
	else
	{
		len_tot = ft_putnbr_count(nbr / 10, len_tot);
		len_tot = ft_putchar_count((nbr % 10) + '0', len_tot);
	}
	return (len_tot);
}
