/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dioux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavagner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:15:40 by mavagner          #+#    #+#             */
/*   Updated: 2017/04/19 16:20:14 by mavagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_dioux(va_list av, char c, t_data *flag)
{
	if (c == 'd' || c == 'i')
		return (ft_printf_itoa(ft_cast_lmod_di(av, flag), flag));
	else if (c == 'o')
		return (ft_printf_itoa_base(ft_cast_lmod_oux(av, flag), 8, flag, c));
	else if (c == 'u')
		return (ft_printf_itoa_base(ft_cast_lmod_oux(av, flag), 10, flag, c));
	else if (c == 'x' || c == 'X')
		return (ft_printf_itoa_base(ft_cast_lmod_oux(av, flag), 16, flag, c));
	else
		return (0);
}
