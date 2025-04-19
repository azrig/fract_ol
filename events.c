/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:03:50 by azrig             #+#    #+#             */
/*   Updated: 2025/04/19 19:03:53 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom *= 0.9;
	ft_render(f);
	return (0);
}

int	handle_key(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		handle_close(f);
	return (0);
}

int	handle_close(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img_ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

void	events_init(t_fractol *f)
{
	mlx_key_hook(f->win, handle_key, f);
	mlx_hook(f->win, 17, 0, handle_close, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
}
