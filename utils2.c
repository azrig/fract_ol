#include "fractol.h"

static int	handle_integer(char *str, int i, double *res)
{
	while (ft_isdigit(str[i]))
	{
		*res = *res * 10.0 + (str[i] - '0');
		i++;
	}
	return (i);
}

static int	handle_fraction(char *str, int i, double *res)
{
	double	frac;

	if (str[i] != '.')
		return (i);
	frac = 0.1;
	i++;
	while (ft_isdigit(str[i]))
	{
		*res += (str[i] - '0') * frac;
		frac *= 0.1;
		i++;
	}
	return (i);
}

double	ft_atod(char *str)
{
	int		i;
	double	res;
	int		sign;

	res = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	i = handle_integer(str, i, &res);
	i = handle_fraction(str, i, &res);
	return (res * sign);
}

static int	is_double_check(char *str)
{
	int	i;
	int	d_b;
	int	d_a;
	int	dot;

	i = 0;
	d_b = 0;
	d_a = 0;
	dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && dot)
			d_a = 1;
		else if (ft_isdigit(str[i]))
			d_b = 1;
		else if (str[i] == '.' && !dot)
			dot = 1;
		else
			return (1);
		i++;
	}
	return (!(d_b && (!dot || d_a)));
}

int	ft_is_double(char *str)
{
	if (!*str)
		return (1);
	return (is_double_check(str));
}
