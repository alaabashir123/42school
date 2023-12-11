/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:39:38 by abashir           #+#    #+#             */
/*   Updated: 2023/09/07 11:10:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imgs_destroy(t_data	*img)
{
	if (img->s_img.img)
		mlx_destroy_image(img->mlx_ptr, img->s_img.img);
	if (img->c_img.img)
		mlx_destroy_image(img->mlx_ptr, img->c_img.img);
	if (img->e_img.img)
		mlx_destroy_image(img->mlx_ptr, img->e_img.img);
	if (img->w_img.img)
		mlx_destroy_image(img->mlx_ptr, img->w_img.img);
	if (img->p_img.img)
		mlx_destroy_image(img->mlx_ptr, img->p_img.img);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free_arr(data->map.array);
	imgs_destroy(data);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == RIGHT)
		move(data, 1, 0);
	else if (keycode == LEFT)
		move(data, -1, 0);
	else if (keycode == UP)
		move(data, 0, -1);
	else if (keycode == DOWN)
		move(data, 0, 1);
	else if (keycode == ESC)
		on_destroy(data);
	return (0);
}

void	ft_event(t_data *data)
{
	data->steps = 0;
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 0L, on_destroy, data);
	mlx_loop(data->mlx_ptr);
}
