/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:31:08 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:31:13 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_close(t_program *w)
{
	free_sprites(w);
	free_map(w->map);
	mlx_destroy_window(w->mlx, w->win.ref);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(0);
}

static t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	win;

	win.ref = mlx_new_window(mlx, widht, height, name);
	win.size.x = widht;
	win.size.y = height;
	return (win);
}

int	main(int argc, char **argv)
{
	t_program	w;

	if (argc == 2)
	{
		if (!ft_map_check(argv[1], &w))
		{	
			map_reader(argv[1], &w);
			w.mlx = mlx_init();
			load_sprites(&w);
			w.moves = 0;
			w.c = 0;
			w.win = ft_new_window(w.mlx,
					w.map_size.x * w.sprites.wall.size.x + 0,
					w.map_size.y * w.sprites.wall.size.y + 32, "so_long");
			display_map(&w);
			ft_display_stats(&w, 0xFFFFFF);
			mlx_hook(w.win.ref, 2, 1L << 0, deal_key, &w);
			mlx_hook(w.win.ref, 17, 0, ft_close, &w);
			mlx_loop(w.mlx);
		}
	}
	else
		ft_printf("Error\nInvalid number of arguments.\n");
	return (0);
}
