/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:06 by rpaulino          #+#    #+#             */
/*   Updated: 2021/05/26 17:44:49 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int how_many_zeros(const char *pointer)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (pointer[i] == '0')
	{
		i++;
		n++;
	}
	return n;
}

int	ft_is_precision(const char *pointer, va_list lista, struct var *global)
{
	int	n;
	int check;


	n = 0;
	if(pointer[0] == '.')
	{
		n++;
		check = ft_atoi(&pointer[1]);
		if (is_type(pointer[1]))
		{
			if (!check && pointer[1] != 'p')
			{
				global->abort = true;
				return 0;
			}
		}
		if (check)
		{
			global->precision_size = check;
			n += len_int(check);
			n += how_many_zeros(&pointer[1]);
		}
		if (pointer[1] == '*')
		{
			global->precision_size = va_arg(lista, int);
			if (!global->precision_size)
				return 0;
			n++;
		}
	} 
	return n;
}

int	ft_prec_error_hand(int parameter, int d, unsigned int i, struct var *global)
{
	int n;

	if (parameter == 'd')
	{
		if (d < 0)
		{
			d *= -1;
			global->print_a_minus = true;
			if (global->flag_zero == 0)
				global->flag_zero++;
		}
		n = len_int(d);
			if (n < global->precision_size)
		global->flag_zero += (global->precision_size - n) + n;
	}
	if (parameter == 'i')
	{
		n = len_int(i);
			if (n < global->precision_size)
		global->flag_zero += (global->precision_size - n) + n;
	}
	if (d)
		return d;
	else
		return i;
}