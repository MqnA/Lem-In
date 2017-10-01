/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:25:44 by mavagner          #+#    #+#             */
/*   Updated: 2017/09/30 21:25:45 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush(t_list **head, void const *content, int content_size)
{
	t_list	*current;

	current = *head;
	if (*head == NULL)
		*head = ft_lstnew(content, content_size);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (t_list*)malloc(sizeof(t_list));
		current->next->content = ft_strdup(content);
		current->next->content_size = content_size;
		current->next->next = NULL;
	}
}
