/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:15:47 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:22:48 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_resolve_format(char **format, va_list av)
{
	t_data	flag;
	int		len;

	len = 0;
	ft_init_struct(&flag);
	while (ft_strchr("#+- .0123456789hljz", **format) && **format)
	{
		ft_init_flag(format, &flag);
		ft_init_width(format, &flag);
		ft_init_prec(format, &flag);
		ft_init_enum(format, &flag);
	}
	if (ft_isalpha(**format) || **format == '%')
	{
		len = ft_check_conv(av, **format, &flag);
	}
	else if ((!(ft_strchr("diouxXcsp", **format))
			&& **format != '%') || !**format)
		return (0);
	(*format)++;
	return (len);
}

int			ft_display(char **format, va_list av)
{
	int		i;
	int		index;
	char	*tmp;

	i = 0;
	index = 0;
	while (**format)
	{
		if (!(tmp = ft_strchr(*format, '%')))
		{
			write(1, *format, ft_strlen(*format));
			index += ft_strlen(*format);
			break ;
		}
		write(1, *format, tmp - *format);
		index += tmp - *format;
		*format = tmp + 1;
		index += ft_resolve_format(format, av);
	}
	return (index);
}
