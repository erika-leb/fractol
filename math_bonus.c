/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:35:07 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/09 16:15:58 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	divergence_burning_ship(t_complex c, t_data *img)
{
	int			i;
	t_complex	z;
	t_complex	tmp;
	double		zm;

	i = 0;
	zm = img->zoom;
	c.re = dim(c.re, WIDTH, -2.5 * zm, 2 * zm) - img->d_a * zm;
	c.im = dim(c.im, HEIGHT, -1.75 * zm, 1.75 * zm) + img->d_b * zm;
	z.re = 0;
	z.im = 0;
	while (i <= ITER_MAX)
	{
		tmp.re = fabs(z.re);
		tmp.im = fabs(z.im);
		z.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		z.im = 2 * tmp.re * tmp.im + c.im;
		if (sqrt(z.re * z.re + z.im * z.im) > 2)
			return (i);
		i++;
	}
	return (1);
}

void	burning_ship_set(t_data *img)
{
	int			x;
	int			y;
	t_complex	c;
	int			d;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c.re = x;
			c.im = y;
			d = divergence_burning_ship(c, img);
			if (d == 1)
				my_mlx_pixel_put(img, x, y, create_trgb(0, 0, 0, 0));
			else
				my_mlx_pixel_put(img, x, y, img->color * (d % 255));
			y++;
		}
		x++;
	}
}
