/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 10:49:39 by qho               #+#    #+#             */
/*   Updated: 2017/05/09 23:44:43 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw(void *mlx, void *win)
{
	int x;
	int y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF00FF);
			x++;
		}
		y++;
	}
}

int expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	(void) *e;
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit (0);
	return (0);
}

int mouse_hook(int button, int x, int y, t_env *e)
{
	(void) *e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	return (0);
}

int main()
{
	t_env e;
	
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "42");
	// sleep(2);
	// draw(e.mlx, e.win);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	
	// sleep(5);
	mlx_loop(e.mlx);
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