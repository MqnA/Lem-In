/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:04:45 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:21:21 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_add_prec(int nlen, t_data *flag)
{
	if (flag->prec < nlen)
		return (flag->prec);
	return (nlen);
}

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

static int	ft_init(char *str, int nlen, t_data *flag)
{
	int		len;

	len = nlen;
	if (flag->neg == 0)
	{
		if (flag->width_min > 0)
			len += ft_add_width(nlen, flag);
	}
	write(1, str, nlen);
	if (flag->neg == 1)
	{
		if (flag->width_min > 0)
			len += ft_add_width(nlen, flag);
	}
	return (len);
}

int			ft_printf_s(char *str, t_data *flag)
{
	int		len;

	if (!str && flag->width_min == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	else if (!str && flag->width_min > 0)
		str = "";
	len = ft_strlen(str);
	if (flag->prec_ok == 1)
		len = ft_add_prec(len, flag);
	return (ft_init(str, len, flag));
}
