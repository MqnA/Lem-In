/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:07:09 by mavagner          #+#    #+#             */
/*   Updated: 2017/01/18 15:35:11 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ilen(uintmax_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_uitoa(uintmax_t n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_ilen(n);
	i = 0;
	if (n == 0)
		len++;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
