/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:21:56 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:15:30 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

intmax_t		ft_cast_lmod_di(va_list av, t_data *flag)
{
	intmax_t	ret;

	ret = va_arg(av, intmax_t);
	if (flag->l_mod != none)
	{
		if (flag->l_mod == hh)
			ret = (char)ret;
		else if (flag->l_mod == h)
			ret = (short)ret;
		else if (flag->l_mod == ll)
			ret = (long)ret;
		else if (flag->l_mod == l)
			ret = (long long)ret;
		else if (flag->l_mod == j)
			ret = (intmax_t)ret;
		else if (flag->l_mod == z)
			ret = (ssize_t)ret;
	}
	else
		ret = (int)ret;
	return (ret);
}

uintmax_t		ft_cast_lmod_oux(va_list av, t_data *flag)
{
	uintmax_t	ret;

	ret = va_arg(av, uintmax_t);
	if (flag->l_mod != none)
	{
		if (flag->l_mod == hh)
			ret = (unsigned char)ret;
		else if (flag->l_mod == h)
			ret = (unsigned short)ret;
		else if (flag->l_mod == l)
			ret = (unsigned long)ret;
		else if (flag->l_mod == ll)
			ret = (unsigned long long)ret;
		else if (flag->l_mod == j)
			ret = (uintmax_t)ret;
		else if (flag->l_mod == z)
			ret = (size_t)ret;
	}
	else
		ret = (unsigned int)ret;
	return (ret);
}
