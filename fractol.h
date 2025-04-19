#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "/usr/include/minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 50
#define ESCAPE_RADIUS 4.0

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx;
	void	*win;
	double	zoom;
	double	julia_x;
	double	julia_y;
	t_img	img;
}				t_fractol;

typedef struct s_cmplx
{
	double	r;
	double	i;
}				t_cmplx;

int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
void	fractol_init(t_fractol *f);
void	ft_mandelbrot(t_fractol *f);
void	ft_render_mandelbrot(t_fractol *f);
void	ft_render_julia(t_fractol *f);
int		get_color(int iteration);
void	my_pixel_put(t_fractol *f, int x, int y, int color);
int		handle_key(int keycode, t_fractol *f);
int		handle_close(t_fractol *f);
int		handle_mouse(int button, int x, int y, t_fractol *f);
void	events_init(t_fractol *f);
void	clean_init(t_fractol *f);
void	cleanup_mlx(t_fractol *f);
void	ft_render(t_fractol *f);
double	ft_atod(char *str);
int		ft_isdigit(char c);
void	ft_julia(t_fractol *f, char *real, char *imaginary);
int		ft_is_double(char *str);
int		parse_julia_args(char *real, char *imaginary);
void	print_usage(void);
int		ft_check_julia_param(char *param);
double	ft_rescale(double v, double o_min, double o_max, double n_min, double n_max);

#endif
