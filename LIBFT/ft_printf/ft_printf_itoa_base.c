/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uitoa_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:13:12 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:20:54 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_add_sharp(t_data *flag, char c)
{
	if (flag->sharp == 1)
	{
		if (ft_strchr("xX", c))
		{
			if (flag->prec_ok == 1 && flag->prec == 0)
			{
				flag->sharp = 0;
				return (0);
			}
			if (flag->zero == 1 && flag->width_min > 0)
				return (0);
			return (2);
		}
		else if (c == 'o')
		{
			if (flag->prec_ok == 1 && flag->prec > 0)
				return (0);
			return (1);
		}
	}
	return (0);
}

static int	ft_add_len(t_data *flag, uintmax_t n, int base, char c)
{
	int	len;

	len = 0;
	if (n == 0 && flag->prec_ok == 0)
	{
		flag->sharp = 0;
		len++;
	}
	len += ft_add_sharp(flag, c);
	while (n != 0)
	{
		n /= base;
		len++;
	}
	if (flag->zero == 1)
	{
		if (flag->width_min > len)
			len += flag->width_min - len + ft_add_sharp(flag, c);
	}
	else if (flag->prec_ok == 1)
	{
		if (flag->prec > len)
			len += flag->prec - len + ft_add_sharp(flag, c);
	}
	return (len);
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
		str = ft_memset(str, ' ', len);
		ft_putstr(str);
		ft_strdel(&str);
	}
	else
		len = 0;
	return (len);
}

static int	ft_init(char *str, int len, t_data *flag)
{
	if (flag->neg == 0)
	{
		if (flag->width_min > 0)
			len += ft_add_width(len, flag);
	}
	ft_putstr(str);
	if (flag->neg == 1)
	{
		if (flag->width_min > 0 && flag->zero == 0)
			len += ft_add_width(len, flag);
	}
	ft_strdel(&str);
	return (len);
}

int			ft_printf_itoa_base(uintmax_t n, int base, t_data *flag, char c)
{
	int		len;
	int		lenc;
	char	*str;

	len = ft_add_len(flag, n, base, c);
	lenc = len;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (-1);
	while (lenc)
	{
		str[lenc - 1] = (n % base) + (n % base > 9 ? 'a' - 10 : '0');
		n /= base;
		lenc--;
	}
	if (flag->sharp && (c == 'x' || c == 'X'))
		str[lenc + 1] = 'x';
	if (c == 'X')
		str = ft_strtoupper(str);
	return (ft_init(str, len, flag));
}
