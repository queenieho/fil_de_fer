/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:49:39 by qho               #+#    #+#             */
/*   Updated: 2017/05/12 23:07:10 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_map *map)
{
	draw_points(map);
	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	(void) *map;
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit (0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_map *map)
{
	(void) *map;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int		main(int ac, char **av)
{
	t_map	map;
	
	if (ac > 2)
		ft_putendl("usage: ./fdf [map_name]");
	else
	{
		// printf("getting map\n");
		ft_map_init(&map);
		WERR1((ft_get_map(av[1], &map) == -1), "issue getting map", -1);
		// ft_print_raw_map(map);
		// ft_putchar('\n');
		// ft_putchar('\n');
		ft_print_map(map);
		// ft_get_map(av[1]);
	}
	// env.mlx = mlx_init();
	// env.win = mlx_new_window(env.mlx, 500, 500, "42");
	// // sleep(2);
	// // draw(env.mlx, env.win);
	mlx_key_hook(map.window, key_hook, &map);
	mlx_mouse_hook(map.window, mouse_hook, &map);
	mlx_expose_hook(map.window, expose_hook, &map);
	// // sleep(5);
	mlx_loop(map.mlx);
	return (0);
}

// int my_key_funct(int keycode, void *param)
// {
// 	(void) param;
// 	printf("key event %d\n", keycode);

// 	return (0);
// }

// int main()
// {
// 	void *mlx;
// 	void *win; //window connection
// 	int x;
// 	int y;

// 	mlx = mlx_init(); // initiates mlx
// 	win = mlx_new_window(mlx, 400, 400, "mlx 42"); // opens the window, uses connector mlx, 400 by 400 size?
// 	y = 50;
// 	while (y < 150)
// 	{
// 		x = 50;
// 		while (x < 150)
// 		{
// 			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);	
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_key_hook(win, my_key_funct, 0);
// 	mlx_loop(mlx); //allows you to see drawings in window
// 	return (0);
// }