/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:30:31 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:30:34 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

static t_img	ft_new_sprite(void *mlx, char *path)
{
	t_img	i;

	i.ref = mlx_xpm_file_to_image(mlx, path, &i.size.x, &i.size.y);
	return (i);
}

int	load_sprites(t_program *w)
{
	w->sprites.wall = ft_new_sprite(w->mlx, "textures/1.xpm");
	w->sprites.floor = ft_new_sprite(w->mlx, "textures/0.xpm");
	w->sprites.coll = ft_new_sprite(w->mlx, "textures/C.xpm");
	w->sprites.exit = ft_new_sprite(w->mlx, "textures/E.xpm");
	w->sprites.hero = ft_new_sprite(w->mlx, "textures/P.xpm");
	w->sprites.enemy = ft_new_sprite(w->mlx, "textures/F.xpm");
	return (0);
}

int	free_sprites(t_program *w)
{
	mlx_destroy_image(w->mlx, w->sprites.wall.ref);
	mlx_destroy_image(w->mlx, w->sprites.floor.ref);
	mlx_destroy_image(w->mlx, w->sprites.coll.ref);
	mlx_destroy_image(w->mlx, w->sprites.exit.ref);
	mlx_destroy_image(w->mlx, w->sprites.hero.ref);
	mlx_destroy_image(w->mlx, w->sprites.enemy.ref);
	return (0);
}

int	print_sprite(t_program *w, void *sprite, t_vector c)
{
	mlx_put_image_to_window(w->mlx, w->win.ref,
		sprite, c.x + 0, c.y + 32);
	return (0);
}
