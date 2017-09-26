/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:16:09 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:21:03 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_add_len(t_data *flag, uintmax_t n, int base)
{
	int		len;

	len = 0;
	if (n == 0 && flag->prec_ok == 0)
		len++;
	len += 2;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	if (flag->zero == 1)
	{
		if (flag->width_min > len)
			len += flag->width_min - len;
	}
	else if (flag->prec_ok == 1)
	{
		if (flag->prec > len - 2)
			len += flag->prec - (len - 2);
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
		write(1, str, ft_strlen(str));
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
		if (flag->width_min > 0 && flag->zero == 0)
			len += ft_add_width(len, flag);
	}
	write(1, str, ft_strlen(str));
	if (flag->neg == 1)
	{
		if (flag->width_min > 0 && flag->zero == 0)
			len += ft_add_width(len, flag);
	}
	ft_strdel(&str);
	return (len);
}

int			ft_printf_p(unsigned long n, t_data *flag)
{
	char	*str;
	int		len;
	int		lenc;

	len = ft_add_len(flag, n, 16);
	lenc = len;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (-1);
	while (lenc)
	{
		str[lenc - 1] = (n % 16) + (n % 16 > 9 ? 'a' - 10 : '0');
		n /= 16;
		lenc--;
	}
	str[lenc + 1] = 'x';
	return (ft_init(str, len, flag));
}
