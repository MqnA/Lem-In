/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:18:18 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:19:07 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_add_width(int len, t_data *flag)
{
	char	*str;

	if (flag->width_min > len)
	{
		len = flag->width_min - len;
		if (!(str = (char*)malloc(sizeof(char) * len)))
			return (-1);
		str[len] = '\0';
		if (flag->zero == 1)
			str = ft_memset(str, '0', len);
		else
			str = ft_memset(str, ' ', len);
		write(1, str, ft_strlen(str));
		ft_strdel(&str);
	}
	else
		len = 0;
	return (len);
}

int			ft_printf_c(char c, t_data *flag)
{
	int		len;

	len = 1;
	if (flag->neg == 0)
	{
		if (flag->width_min > 0)
			len += ft_add_width(len, flag);
	}
	ft_putchar(c);
	if (flag->neg == 1)
	{
		if (flag->width_min > 0)
			len += ft_add_width(len, flag);
	}
	return (len);
}
