/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:37:19 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/20 15:55:07 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_upper(unsigned int n, int len_tot)
{
	if (n > 15)
	{
		len_tot = ft_puthexa_upper((n / 16), len_tot);
		len_tot = ft_puthexa_upper((n % 16), len_tot);
	}
	else if (n < 10)
		len_tot = ft_putchar_count((n + '0'), len_tot);
	else
		len_tot = ft_putchar_count(((char)n - 10 + 'A'), len_tot);
	return (len_tot);
}
