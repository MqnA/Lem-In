/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:02:19 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:20:24 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_init_struct(t_data *flag)
{
	flag->sharp = 0;
	flag->pos = 0;
	flag->prec = 0;
	flag->prec_ok = 0;
	flag->space = 0;
	flag->neg = 0;
	flag->width_min = 0;
	flag->l_mod = none;
}

void	ft_init_enum(char **format, t_data *flag)
{
	if (ft_strchr(L_MOD, **format) && **format != '\0')
	{
		if (flag->l_mod == none)
		{
			if (**format == 'h' && *(*format + 1) == 'h')
			{
				flag->l_mod = hh;
				(*format)++;
			}
			else if (**format == 'l' && *(*format + 1) == 'h')
			{
				flag->l_mod = ll;
				(*format)++;
			}
			else if (**format == 'h')
				flag->l_mod = h;
			else if (**format == 'l')
				flag->l_mod = l;
			else if (**format == 'j')
				flag->l_mod = j;
			else if (**format == 'z')
				flag->l_mod = z;
		}
		(*format)++;
	}
}

void	ft_init_flag(char **format, t_data *flag)
{
	while (ft_strchr(FLAGS, **format) && **format != '\0')
	{
		if (**format == '#')
			flag->sharp = 1;
		else if (**format == '0' && flag->neg == 0)
			flag->zero = 1;
		else if (**format == '-')
		{
			if (flag->zero == 1 || flag->space == 1)
				flag->zero = 0;
			flag->neg = 1;
		}
		else if (**format == '+')
		{
			if (flag->space == 1)
				flag->space = 0;
			flag->pos = 1;
		}
		else if (**format == ' ' && flag->pos == 0 && flag->neg == 0)
			flag->space = 1;
		(*format)++;
		while (**format == *(*format - 1))
			(*format)++;
	}
}

void	ft_init_width(char **format, t_data *flag)
{
	if (ft_isdigit(**format) && **format != '\0')
	{
		while (ft_isdigit(**format))
		{
			flag->width_min = (flag->width_min * 10) + (**format - '0');
			(*format)++;
		}
	}
}

void	ft_init_prec(char **format, t_data *flag)
{
	if (**format == '.' && **format != '\0')
	{
		flag->prec_ok = 1;
		(*format)++;
		if (!(ft_isdigit(**format)))
			return ;
		while (ft_isdigit(**format))
		{
			flag->prec = (flag->prec * 10) + (**format - '0');
			(*format)++;
		}
	}
}
