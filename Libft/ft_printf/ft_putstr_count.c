/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:17:08 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/20 16:14:24 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *s, int len_tot)
{
	if (!s)
	{
		len_tot = ft_putstr_count("(null)", len_tot);
		return (len_tot);
	}
	while (*s)
	{
		len_tot = ft_putchar_count(*s, len_tot);
		s++;
	}
	return (len_tot);
}
