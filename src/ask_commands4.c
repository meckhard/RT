/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_commands4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:25:41 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/12 16:12:30 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_objects(t_objects *ob)
{
	ob->objects = (char ****)malloc(sizeof(char ***) * 2);
	ob->objects[0] = ob->commands;
	ob->objects[1] = ob->lighting;
}
