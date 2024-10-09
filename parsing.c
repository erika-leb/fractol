/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:40:33 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/09 15:04:38 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_and_quit(void)
{
	ft_putstr("\nThis program creates fractals.\n");
	ft_putstr("\nYou can choose the complex value related to the fractal.\n");
	ft_putstr("\nYou need to run this program with valid arguments\n");
	ft_putstr("\nThe first argument is the name of the fractal set :\n");
	ft_putstr("'julia' or 'mandelbrot' or 'burning ship'\n");
	ft_putstr("\nThe second argument (optional) is the  real part 'x'.\n");
	ft_putstr("It must be a float\n");
	ft_putstr("\nThe third argmuent (optional) is the imaginary part 'y'.\n");
	ft_putstr("It must be a float\n");
	ft_putstr("\nIf only x is given, 'y' will be considered as 0\n\n");
	exit(0);
}

double	ft_atoi(char *str)
{
	int		i;
	double	r;
	int		v;
	int		n;

	i = 0;
	r = 0;
	v = -1;
	n = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (str[i] == '.')
	{
		n++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && n == 0)
		r = r * 10 + str[i++] - '0';
	while (str[i] >= '0' && str[i] <= '9' && n == 1)
		r = r + (str[i++] - '0') * pow(10, v--);
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		r = r + (str[i++] - '0') * pow(10, v--);
	return (r);
}

void	put_arg(int argc, char **argv, t_arg *ag)
{
	(void) argc;
	if (argv[2][0] == '-')
		ag->x = ft_atoi(argv[2]) * (-1);
	else
		ag->x = ft_atoi(argv[2]);
	if (argv[3] && argv[3][0] == '-')
		ag->y = ft_atoi(argv[3]) * 1;
	else if (argv[3] && argv[3][0] != '-')
		ag->y = ft_atoi(argv[3]);
	if (!argv[3])
		ag->y = 0;
}

void	handle_error(int argc, char **argv)
{
	if (argc == 1 || argc > 4)
		error_and_quit();
	if (ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "Julia") != 0
		&& ft_strcmp(argv[1], "burning ship") != 0
		&& ft_strcmp(argv[1], "Burning ship") != 0
		&& ft_strcmp(argv[1], "Mandelbrot") != 0)
		error_and_quit();
	if ((argv[2] && is_float(argv[2]) == -1)
		|| (argv[2] && argv[3] && is_float(argv[3]) == -1))
		error_and_quit();
}

t_arg	parsing(int argc, char **argv)
{
	t_arg	ag;

	handle_error(argc, argv);
	if (ft_strcmp(argv[1], "julia") == 0 || ft_strcmp(argv[1], "Julia") == 0)
		ag.set = 1;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
		ag.set = 2;
	if (ft_strcmp(argv[1], "burning ship") == 0
		|| ft_strcmp(argv[1], "Burning ship") == 0)
		ag.set = 3;
	ag.x = 0.3;
	ag.y = 0.5;
	if (argv[2])
		put_arg(argc, argv, &ag);
	return (ag);
}
