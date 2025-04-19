#include "fractol.h"

void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img.img_ptr = NULL;
	f->img.addr = NULL;
	f->img.bpp = 0;
	f->img.line_len = 0;
	f->img.endian = 0;
	f->zoom = 1.0;
}

void	cleanup_mlx(t_fractol *f)
{
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit((ft_putstr_fd("error\n", 2), 1));
}

void	fractol_init(t_fractol *f)
{
	clean_init(f);
	f->mlx = mlx_init();
	if (!f->mlx)
		cleanup_mlx(f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		cleanup_mlx(f);
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		cleanup_mlx(f);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	events_init(f);
}
