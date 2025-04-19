#include "fractol.h"
#include <stdio.h>

int	get_color(int iteration)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == MAX_ITER)
		return (0x000000);
	t = (double)iteration / MAX_ITER;
	r = (int)(255 * fabs(sin(3.0 * M_PI * t)));
	g = (int)(255 * fabs(sin(3.0 * M_PI * t + 2 * M_PI / 3)));
	b = (int)(255 * fabs(sin(3.0 * M_PI * t + 4 * M_PI / 3)));
	
	return ((r << 16) | (g << 8) | b);
}

void	my_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.line_len + x * (f->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_render(t_fractol *f)
{
	if (!ft_strncmp(f->name, "Mandelbrot", 10))
		ft_render_mandelbrot(f);
	else if (!ft_strncmp(f->name, "Julia", 5))
		ft_render_julia(f);
}

double	ft_rescale(double v, double o_min, double o_max, double n_min, double n_max)
{
	return ((v - o_min) * (n_max - n_min) / (o_max - o_min) + n_min);
}