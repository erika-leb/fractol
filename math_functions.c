/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:46:57 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/09 18:55:31 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	dim(double x, double old_max, double new_min, double new_max)
{
	double	r;
	double	old_min;

	old_min = 0;
	r = ((x - old_min) * (new_max - new_min)) / (old_max - old_min) + new_min;
	return (r);
}

int	divergence_julia(int x, int y, t_complex c, t_data *img)
{
	int			i;
	t_complex	z;
	t_complex	tmp;
	double		zm;

	i = 0;
	zm = img->zoom;
	z.re = dim((double) x, WIDTH, 2 * zm, -2 * zm) - img->d_a * zm;
	z.im = dim((double) y, HEIGHT, 2.5 * zm, -2.5 * zm) + img->d_b * zm;
	while (i <= ITER_MAX)
	{
		tmp.re = z.re;
		tmp.im = z.im;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		z.im = 2 * tmp.re * tmp.im + c.im;
		if (sqrt(z.re * z.re + z.im * z.im) > 2)
			return (i);
		i++;
	}
	return (1);
}

int	divergence_mandelbrot(t_complex c, t_data *img)
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
		tmp.re = z.re;
		tmp.im = z.im;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		z.im = 2 * tmp.re * tmp.im + c.im;
		if (sqrt(z.re * z.re + z.im * z.im) > 2)
			return (i);
		i++;
	}
	return (1);
}

void	julia_set(t_data *img)
{
	int			x;
	int			y;
	t_complex	c;
	int			d;

	x = 0;
	c.re = img->x;
	c.im = img->y;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			d = divergence_julia(x, y, c, img);
			if (d == 1)
				my_mlx_pixel_put(img, x, y, create_trgb(0, 0, 0, 0));
			else
				my_mlx_pixel_put(img, x, y, create_shades(d) * (d % 255));
			y++;
		}
		x++;
	}
}

void	mandelbrot_set(t_data *img)
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
			d = divergence_mandelbrot(c, img);
			if (d == 1)
				my_mlx_pixel_put(img, x, y, create_trgb(0, 0, 0, 0));
			else
				my_mlx_pixel_put(img, x, y, img->color * (d % 255));
			y++;
		}
		x++;
	}
}
