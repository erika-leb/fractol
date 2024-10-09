/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:46:57 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/09 15:30:51 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_pattern(t_data *img)
{
	if (img->set == 1)
		julia_set(img);
	if (img->set == 2)
		mandelbrot_set(img);
	if (img->set == 3)
		burning_ship_set(img);
}

void	error_exit(void)
{
	perror("Error");
	exit(1);
}

t_data	init_vars(t_arg ag)
{
	t_data	vars;

	vars.x = ag.x;
	vars.y = ag.y;
	vars.d_a = 0;
	vars.d_b = 0;
	vars.set = ag.set;
	vars.zoom = 1;
	vars.color = create_trgb(0, 50, 205, 50);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		error_exit();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "mlx 42");
	if (vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		error_exit();
	}
	vars.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.line, &vars. end);
	return (vars);
}

int	main(int argc, char **argv)
{
	t_data	vars;
	t_arg	ag;

	ag = parsing(argc, argv);
	vars = init_vars(ag);
	handle_events(&vars);
	return (0);
}
