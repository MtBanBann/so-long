/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:31:53 by afavier           #+#    #+#             */
/*   Updated: 2024/02/16 23:23:01 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"
#include "../minilibx-linux/mlx.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>


int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		map_test(argv);

	}
	return (0);
}

int open_window(char **map)
{
	char	*relative_path = "./slamereche.xpm";
	int		img_width;
	int		img_height;
	int len;
	int i;
	int y;
	int height;
	int width;
	t_data	img;
	t_vars vars;

	i = 0;
	y = 0;
	height = 0;
	width = 0;
	len = ft_strlen(map[0]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so long");
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	if (img.img == NULL)
	{
		printf("Error: Failed to load image\n");
		exit(1);
	}
	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y < 5)
	{
		while (i < len - 2)
		{
			if (map[y][i] == '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, width, height);
			}
			width = width + 120;
			i++;			
		}
		width = 0;
		height = height + 130;
		i = 0;
		y++;
	}
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, height, height);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 211, 238);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	mlx_loop(vars.mlx);

    return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	close_window(int keycode, t_vars *vars)
{
	if(keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}