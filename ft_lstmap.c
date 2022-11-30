/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:54:25 by gsaile            #+#    #+#             */
/*   Updated: 2022/11/21 16:31:02 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*current;

	(void)del;
	if (!lst)
		return (NULL);
	current = lst;
	ret = ft_lstnew(f(current->content));
	current = current->next;
	while (current)
	{
		ft_lstadd_back(&ret, ft_lstnew(f(current->content)));
		current = current->next;
	}
	return (ret);
}
