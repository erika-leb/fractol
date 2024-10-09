/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:46:57 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/08 23:17:48 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_shades(int d)
{
	int	r;
	int	g;
	int	b;

	b = 255;
	g = 255;
	r = 255;
	if (d < 50)
	{
		r = (d * 255) / 25;
		g = 255 - (d * 255) / 30;
		b = 0;
	}
	else if (d < 100)
	{
		g = ((d - 50) * 255) / 50;
		r = 255 - (g * 255) / 255;
		b = 0;
	}
	else if (d < 150)
	{
		b = (d - 100) * 255 / 50;
		r = 255 - (b * 255) / 255;
	}
	return (r << 16 | g << 8 | b);
}
