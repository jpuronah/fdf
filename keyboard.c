/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:12:21 by jpuronah          #+#    #+#             */
/*   Updated: 2022/06/05 20:55:39 by jpuronah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 20,
		WHITE, "Press 'ESC' to EXIT PROGRAM");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 40,
		WHITE, "Move: 'WASD'");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 60,
		WHITE, "Zoom: '+' & '-'");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 80,
		WHITE, "Rotate: ARROW KEYS");
	mlx_string_put(mlx->mlxptr, mlx->winptr, 20, 100,
		WHITE, "Reset: 'R'");
}

static int	exit_fdf(t_mlx *mlx)
{
	delete_image(mlx, mlx->image);
	mlx_destroy_window(mlx->mlxptr, mlx->winptr);
	//system("leaks fdf");
	exit (EXIT_SUCCESS);
}

void	reset_camera(t_mlx *mlx)
{
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->scale = 32;
	mlx->cam->offsetx = WIN_WIDTH / 2;
	mlx->cam->offsety = WIN_HEIGHT / 2;
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == 53)
		exit_fdf(mlx);
	/* if key == 1
			view 1
		else
			view 2	*/
	if (key == 24)
		mlx->cam->scale = mlx->cam->scale + 1;
	if (key == 27)
		mlx->cam->scale = mlx->cam->scale - 1;
	if (key == 13)
		mlx->cam->offsety -= 10;
	if (key == 0)
		mlx->cam->offsetx -= 10;
	if (key == 1)
		mlx->cam->offsety += 10;
	if (key == 2)
		mlx->cam->offsetx += 10;
	if (key == 126)
		mlx->cam->x += 0.1;
	if (key == 123)
		mlx->cam->y -= 0.1;
	if (key == 125)
		mlx->cam->x -= 0.1;
	if (key == 124)
		mlx->cam->y += 0.1;
	if (key == 15)
		reset_camera(mlx);
	render(mlx);
	menu(mlx);
	return (0);
}

/*
int		key_event(int key, t_mlx *mlx)
{
	(void)mlx;

	if (key == XK_Escape)
		free_and_exit(key, mlx);
	if (ft_isdigit(key) == 1)
	{
		if (key == '1')
			mlx->cam->scale = mlx->cam->scale + 1;
		if (key == '2')
			mlx->cam->scale = mlx->cam->scale - 1;
		//render(mlx);
		//printf("%d\n", i);
	}
	if (key == 'w')
		mlx->cam->offsety -= 10;
	if (key == 'a')
		mlx->cam->offsetx -= 10;
	if (key == 's')
		mlx->cam->offsety += 10;
	if (key == 'd')
		mlx->cam->offsetx += 10;

	if (key == 65362)
		mlx->cam->x += 0.1;
	if (key == 65361)
		mlx->cam->y -= 0.1;
	if (key == 65364)
		mlx->cam->x -= 0.1;
	if (key == 65363)
		mlx->cam->y += 0.1;
	if (key == 'o')
	{
		mlx->map->depth_max /= 2;
		mlx->map->depth_min /= 2;
	}
	if (key == 'p')
	{
		mlx->map->depth_max += 10;
		mlx->map->depth_min += 10;
	}
	render(mlx);
	menu(mlx);
	return (0);
}*/

/*
int	key_event(int key, t_mlx *mlx)
{
	if (key == 65307)
		exit(EXIT_SUCCESS);
	else if (key == '0')
	{
		mlx->cam->x = 0;
		mlx->cam->y = 0;
		mlx->cam->offsetx = WIN_WIDTH / 2;
		mlx->cam->offsety = WIN_HEIGHT / 2;
	}
	if (key == '1')
	{
		mlx->cam->x = 0.5;
		mlx->cam->y = 0.5;
		mlx->cam->offsetx = WIN_WIDTH / 2;
		mlx->cam->offsety = WIN_HEIGHT / 2;
	}
	if (key == '2')
	{
		mlx->cam->x = 10;
		mlx->cam->y = 10;
		mlx->cam->offsetx = WIN_WIDTH / 2;
		mlx->cam->offsety = WIN_HEIGHT / 2;
	}
	if (key == '+')
		mlx->cam->scale = mlx->cam->scale + 1;
	if (key == '-')
		mlx->cam->scale = mlx->cam->scale - 1;
	render(mlx);
	menu(mlx);
	return (0);
}
*/