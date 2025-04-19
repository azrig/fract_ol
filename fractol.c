/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:04:11 by azrig             #+#    #+#             */
/*   Updated: 2025/04/19 19:38:59 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ci_strcmp(const char *s1, const char *s2)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (s1[i] && s2[i])
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 >= 'A' && c1 <= 'Z')
			c1 += 32;
		if (c2 >= 'A' && c2 <= 'Z')
			c2 += 32;
		if (c1 != c2)
			return (0);
		i++;
	}
	return (s1[i] == '\0' && s2[i] == '\0');
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		return (print_usage(), 1);
	if (ci_strcmp(av[1], "mandelbrot") && ac == 2)
	{
		f.name = "Mandelbrot";
		ft_mandelbrot(&f);
	}
	else if (ci_strcmp(av[1], "julia")
		&& ac == 4 && !parse_julia_args(av[2], av[3]))
	{
		f.name = "Julia";
		ft_julia(&f, av[2], av[3]);
	}
	else
	{
		print_usage();
		exit(1);
	}
	return (0);
}
