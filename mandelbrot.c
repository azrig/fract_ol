/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:04:37 by azrig             #+#    #+#             */
/*   Updated: 2025/04/19 19:04:42 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot_set(t_cmplx c)
{
	t_cmplx	z;
	int		i;
	double	temp_r;
	double	temp_i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		temp_r = (z.r * z.r) - (z.i * z.i) + c.r;
		temp_i = (2 * z.r * z.i) + c.i;
		z.r = temp_r;
		z.i = temp_i;
		if (z.r * z.r + z.i * z.i > ESCAPE_RADIUS)
			return (i);
		i++;
	}
	return (MAX_ITER);
}

void	ft_render_mandelbrot(t_fractol *f)
{
	int			x;
	int			y;
	t_cmplx		c;
	int			nb_iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.r = ft_rescale((double)x, 0, WIDTH, -2.0, 2.0) * f->zoom;
			c.i = ft_rescale((double)y, 0, HEIGHT, -2.0, 2.0) * f->zoom;
			nb_iter = mandelbrot_set(c);
			my_pixel_put(f, x, y, get_color(nb_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}

void	ft_mandelbrot(t_fractol	*f)
{
	fractol_init(f);
	ft_render_mandelbrot(f);
	mlx_loop(f->mlx);
}
