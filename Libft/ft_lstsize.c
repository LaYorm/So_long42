/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:18:02 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/17 09:18:04 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	size_list;

	size_list = 0;
	while (lst)
	{
		size_list++;
		lst = lst->next;
	}
	return (size_list);
}
