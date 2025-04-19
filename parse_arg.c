#include "fractol.h"

int	ft_check_julia_param(char *param)
{
	double	res;

	if (ft_is_double(param) != 0)
		return (1);
	res = ft_atod(param);
	if (res < -2.0 || res > 2.0)
		return (2);
	return (0);
}

int	parse_julia_args(char *real, char *img)
{
	int	r;
	int	i;

	r = ft_check_julia_param(real);
	i = ft_check_julia_param(img);
	if (r == 1 || i == 1)
		return (1);
	else if (r == 2 || i == 2)
		return (1);
	return (0);
}

void	print_usage(void)
{
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("  ./fractol Mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol Julia <real> <imaginary>\n", 2);
	ft_putstr_fd("\nExamples:\n", 2);
	ft_putstr_fd("  ./fractol Julia 0.285 0.01\n", 2);
	ft_putstr_fd("  ./fractol Julia -0.7269 0.1889\n", 2);
	ft_putstr_fd("\nNote: Julia parameters should be between -2.0 and 2.0\n", 2);
}