/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:06:05 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/09 16:13:45 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_input(int keysym, t_data	*vars)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	if (keysym == XK_c)
		vars->color *= (255 * 255 * 255) / 100;
	if (keysym == XK_Right)
		vars->d_a = vars->d_a - (4.0 - vars->zoom) / 5.0;
	if (keysym == XK_Left)
		vars->d_a = vars->d_a + (4.0 - vars->zoom) / 5.0;
	if (keysym == XK_Up)
		vars->d_b = vars->d_b - (4.0 - vars->zoom) / 5.0;
	if (keysym == XK_Down)
		vars->d_b = vars->d_b + (4.0 - vars->zoom) / 5.0;
	create_pattern(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	ft_close(t_data	*vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	mouse_hook(int button, int x, int y, t_data *vars)
{
	double	var;

	(void) x;
	(void) y;
	if (button == 4)
		vars->zoom = vars->zoom * 0.9;
	if (button == 5)
		vars->zoom = vars->zoom / 0.9;
	var = vars->zoom / 255;
	vars->color = dim(vars->color, 255, 0 + var, 255 - var);
	create_pattern(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

void	handle_events(t_data *vars)
{
	create_pattern(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_key_hook(vars->win, &handle_input, vars);
	mlx_mouse_hook(vars->win, &mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, &ft_close, vars);
	mlx_loop(vars->mlx);
}
