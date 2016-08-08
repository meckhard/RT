/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:11:07 by meckhard          #+#    #+#             */
/*   Updated: 2016/08/08 11:44:42 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "structs.h"
# include "functions.h"
# include "../libft/libft.h"

# define WIN_X 800
# define WIN_Y 600

# define ESCAPE 53

# define RED	0xFF0000
# define MAROON	0x800000
# define ORANGE	0xFF5733
# define YELLOW	0xFFFF00

# define R_MESS01 "\e[31mError: Please define a map. './rtv1 maps/..'\n"
# define R_MESS02 "\e[31mError: Command not found.\n"
# define R_MESS03 "\e[31mError: Command failed.\n"
# define R_MESS04 "\e[31mError:	Memory problem.\n"
# define R_MESS05 "\e[31mError:	No coordinates specified.\n"
# define R_MESS06 "\e[31mError: Coordinates specified incorrectly.\n"
# define R_MESS07 "\e[31mError: Please try again.\n"
# define R_MESS08 R_MESS05 R_MESS07
# define R_MESS09 R_MESS06 R_MESS07
# define R_MESS10 "\e[31mError: Incorrect shape.\n"
# define R_MESS11 R_MESS10 R_MESS07
# define R_MESS12 "\e[31mError: The amount of commands given is non-valid.\n"

#endif
