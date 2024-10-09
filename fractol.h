/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:44:21 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/09 16:13:06 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# define WIDTH 1000
# define HEIGHT 600
# define ITER_MAX 300

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
	int			set;
	double		x;
	double		y;
	double		zoom;
	double		d_a;
	double		d_b;
	int			color;
}	t_data;

typedef struct s_arg
{
	int			set;
	double		x;
	double		y;
}	t_arg;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

void	create_pattern(t_data *img);
void	error_exit(void);
t_data	init_vars(t_arg ag);

int		handle_input(int keysym, t_data	*vars);
int		ft_close(t_data	*vars);
int		mouse_hook(int button, int x, int y, t_data *vars);
void	handle_events(t_data *vars);

double	dim(double x, double old_max, double new_min, double new_max);
int		divergence_julia(int x, int y, t_complex c, t_data *img);
int		divergence_mandelbrot(t_complex c, t_data *img);
void	julia_set(t_data *img);
void	mandelbrot_set(t_data *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		create_shades(int d);

void	error_and_quit(void);
double	ft_atoi(char *str);
void	put_arg(int argc, char **argv, t_arg *ag);
void	handle_error(int argc, char **argv);
t_arg	parsing(int argc, char **argv);

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		no_number(char *str);
int		is_float(char *str);

int		divergence_burning_ship(t_complex c, t_data *img);
void	burning_ship_set(t_data *img);

#endif