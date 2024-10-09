/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-borg <ele-borg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:57:27 by ele-borg          #+#    #+#             */
/*   Updated: 2024/10/07 13:44:21 by ele-borg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	no_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && !str[1])
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

int	is_float(char *str)
{
	int		i;
	int		v;
	int		n;

	i = 0;
	v = 0;
	n = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	if (str[i++] == '.')
		v++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i++] <= '9')
		n++;
	if (str[i++] == '.')
		v++;
	while (str[i] >= '0' && str[i++] <= '9')
		n++;
	if (v > 1 || n > 7 || no_number(str) == 0)
		return (-1);
	return (0);
}
