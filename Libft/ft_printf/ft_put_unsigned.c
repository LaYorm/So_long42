/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:21:02 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/20 16:09:55 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int nbr, int len_tot)
{
	if (nbr < 10)
		len_tot = ft_putchar_count((nbr + '0'), len_tot);
	else
	{
		len_tot = ft_putnbr_count(nbr / 10, len_tot);
		len_tot = ft_putchar_count((nbr % 10) + '0', len_tot);
	}
	return (len_tot);
}
