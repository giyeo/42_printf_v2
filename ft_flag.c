/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:21 by rpaulino          #+#    #+#             */
/*   Updated: 2021/05/20 17:33:25 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_is_flag(const char *pointer, va_list lista, struct var *global)
{
	int n;

	n = 0;
	if (pointer[0] == '-')
	{
		n++;
		if (pointer[1] == '*')
		{
			global->flag_minus = va_arg(lista, int);
			if (global->flag_minus < 0)
				global->flag_minus *= -1;
			if (!global->flag_minus)
				return 0;
			n++;
		}
		if (ft_isdigit(pointer[1]))
		{
			global->flag_minus = ft_atoi(&pointer[1]);
			n += len_int(ft_atoi(&pointer[1]));
		}
	}
	if (pointer[0] == '0')
	{
		n++;
		if (pointer[1] == '*')
		{
			global->flag_zero = va_arg(lista, int);
			if (global->flag_zero < 0)
			{
				global->flag_minus = global->flag_zero * -1;
				global->flag_zero = 0;
				n++;
				return n;
			}
			if (!global->flag_zero)
				return 0;
			n++;
		}
		if (ft_isdigit(pointer[1]))
		{
			global->flag_zero = ft_atoi(&pointer[1]);
			n += len_int(ft_atoi(&pointer[1]));
		}
	}
	return n;
}