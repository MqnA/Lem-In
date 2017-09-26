/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:13:25 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:20:45 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_add_prefix(t_data *flag, intmax_t n)
{
	int len;

	len = 0;
	if ((n == 0 && flag->prec_ok == 0) || n < 0)
	{
		if (n < 0)
			flag->space = 0;
		len++;
	}
	if (flag->pos == 1 && n >= 0)
		len++;
	return (len);
}

static int	ft_add_len(int len, t_data *flag, intmax_t n)
{
	intmax_t nc;

	nc = n;
	while (nc != 0)
	{
		nc /= 10;
		len++;
	}
	if (flag->zero == 1 && flag->prec_ok == 0)
	{
		if (flag->width_min > len)
			len += flag->width_min - len;
		if (flag->space && flag->width_min > 0)
			len--;
	}
	else if (flag->prec_ok == 1 && flag->prec >= len)
	{
		len += flag->prec - len;
		if (n < 0 || flag->pos == 1)
			len++;
	}
	return (len);
}

static int	ft_add_width(int len, t_data *flag)
{
	char	*str;

	if (flag->width_min > len || flag->space == 1)
	{
		if (flag->width_min > len)
			len = flag->width_min - len;
		else
			len = 1;
		if (!(str = (char*)malloc(sizeof(char) * len)))
			return (-1);
		str[len] = '\0';
		str = ft_memset(str, ' ', len);
		write(1, str, len);
		ft_strdel(&str);
	}
	else
		len = 0;
	return (len);
}

static int	ft_init(char *str, int len, t_data *flag)
{
	if (flag->prec_ok == 1)
		flag->zero = 0;
	if (flag->neg == 0)
	{
		if ((flag->width_min > 0 && flag->zero == 0) || flag->space)
		{
			len += ft_add_width(len, flag);
		}
	}
	write(1, str, ft_strlen(str));
	if (flag->neg == 1)
	{
		if ((flag->width_min > 0 && flag->zero == 0) || flag->space)
		{
			len += ft_add_width(len, flag);
		}
	}
	ft_strdel(&str);
	return (len);
}

int			ft_printf_itoa(intmax_t n, t_data *flag)
{
	int		len;
	int		lenc;
	int		sign;
	char	*str;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_add_prefix(flag, n);
	len = ft_add_len(len, flag, n);
	lenc = len;
	if (!(str = ft_strnew(sizeof(char) * len)))
		return (-1);
	while (lenc)
	{
		str[lenc - 1] = sign * (n % 10) + '0';
		n = n / 10;
		lenc--;
	}
	if (sign == -1)
		str[lenc] = '-';
	else if (flag->pos == 1)
		str[lenc] = '+';
	return (ft_init(str, len, flag));
}
