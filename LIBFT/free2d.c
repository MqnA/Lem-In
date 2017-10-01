/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:25:18 by mavagner          #+#    #+#             */
/*   Updated: 2017/09/30 21:25:20 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_2d(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
	{
		ft_bzero(lines[i], ft_strlen(lines[i]));
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
}
