/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 09:48:16 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/04 09:50:11 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags	init_flags(void)
{
	t_flags	fl;

	fl.has_flags = 0;
	fl.minus = 0;
	fl.plus = 0;
	fl.zero = 0;
	fl.hash = 0;
	fl.space = 0;
	fl.padding = 0;
	fl.prec = 0;
	fl.ip = 0;
	fl.pad = ' ';
	return (fl);
}

int		is_pmodifier(char c)
{
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z' || c == 'u')
		return (1);
	return (0);
}

int		is_pflag(char c)
{
	if (c == '-' || c == '+' || c == '0' || c == '#' || c == ' ' || c == '.')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

int		is_pnumeric(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'i'
			|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		is_psigned(char c)
{
	if (c == 'a' || c == 'A' || c == 'd' || c == 'e' || c == 'E' || c == 'F'
			|| c == 'g' || c == 'G' || c == 'i')
		return (1);
	return (0);
}
