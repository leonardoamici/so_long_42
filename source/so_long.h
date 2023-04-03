/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:31:19 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:31:25 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_window
{
	void		*ref;
	t_vector	size;
}		t_window;

typedef struct s_img
{
	void		*ref;
	t_vector	size;
}		t_img;

typedef struct s_sprites
{
	t_img		wall;
	t_img		floor;
	t_img		coll;
	t_img		exit;
	t_img		hero;
	t_img		enemy;
}		t_sprites;

typedef struct s_program
{
	void		*mlx;
	t_window	win;
	t_sprites	sprites;
	t_vector	sprite_pos;
	char		**map;
	t_vector	map_size;
	t_vector	hero_pos;
	int			coll;
	int			c;
	int			moves;
}		t_program;

int		deal_key(int tasto, t_program *w);
int		ft_close(t_program *w);
int		map_reader(char *path, t_program *w);
int		ft_map_check(char *path, t_program *w);
int		display_map(t_program *w);
int		free_map(char **map);
int		flood_fill(char **tab, t_vector size, t_vector begin);
int		load_sprites(t_program *w);
int		free_sprites(t_program *w);
int		print_sprite(t_program *w, void *sprite, t_vector c);
int		type_check(char *path);
int		ft_display_stats(t_program *w, int color);
char	*ft_free_join(char *str1, char *str2);

#endif
