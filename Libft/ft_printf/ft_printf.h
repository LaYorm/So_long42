/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:06:48 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/20 15:59:36 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// --------------Includes ------------------------

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

// ---------------Main Functions -----------------

int	ft_printf(const char *str, ...);
int	ft_write_arg(char c, va_list args, int len_tot);
int	ft_is_param(char c);
int	ft_check_valid(const char *str);

// -------------Functions that write--------------

int	ft_put_adress(uintptr_t n, int len_tot, int if_ptr);
int	ft_puthexa_lower(unsigned int n, int len_tot);
int	ft_puthexa_upper(unsigned int n, int len_tot);
int	ft_putchar_count(char c, int len_tot);
int	ft_putnbr_count(int n, int len_tot);
int	ft_put_unsigned(unsigned int nbr, int len_tot);
int	ft_putstr_count(char *s, int len_tot);

#endif
