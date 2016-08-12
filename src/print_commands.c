/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 16:51:10 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/12 12:44:26 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	put_2d_array(char **array)
{
	unsigned int			j;

	j = 0;
	while (array[j] && array[j] != NULL)
	{
		ft_putstr(array[j]);
		j++;
	}
	ft_putchar('\n');
}
