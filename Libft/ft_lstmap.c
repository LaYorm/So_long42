/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorimek <yorimek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:18:13 by yorimek           #+#    #+#             */
/*   Updated: 2025/11/18 09:52:07 by yorimek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(t_list **list, void (*del)(void *), void *new_content)
{
	if (new_content)
		free (new_content);
	ft_lstclear(list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_list;
	t_list	*new_node;
	void	*new_content;

	head_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (ft_free(&head_list, del, NULL));
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (ft_free(&head_list, del, new_content));
		ft_lstadd_back(&head_list, new_node);
		lst = lst->next;
	}
	return (head_list);
}
