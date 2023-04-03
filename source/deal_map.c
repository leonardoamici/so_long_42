/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:30:54 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:30:59 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
	return (0);
}

static int	map_size(t_program *w)
{
	w->map_size.x = 0;
	w->map_size.y = 0;
	while (w->map[0][w->map_size.x] != '\0')
		w->map_size.x++;
	while (1)
	{
		if (!w->map[w->map_size.y])
		{
			break ;
		}
		w->map_size.y++;
	}
	return (0);
}

int	map_reader(char *path, t_program *w)
{
	int		fd;
	char	*rawmap;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		rawmap = malloc(1);
		*rawmap = '\0';
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			rawmap = ft_free_join(rawmap, line);
		}
		w->map = ft_split(rawmap, '\n');
		free(rawmap);
		map_size(w);
	}
	close(fd);
	return (fd);
}

static int	check_print(int x, int y, t_program *w)
{
	if (w->map[y][x] == '1')
		print_sprite(w, w->sprites.wall.ref, w->sprite_pos);
	else if (w->map[y][x] == '0')
		print_sprite(w, w->sprites.floor.ref, w->sprite_pos);
	else if (w->map[y][x] == 'P')
		print_sprite(w, w->sprites.hero.ref, w->sprite_pos);
	else if (w->map[y][x] == 'C')
		print_sprite(w, w->sprites.coll.ref, w->sprite_pos);
	else if (w->map[y][x] == 'E')
		print_sprite(w, w->sprites.exit.ref, w->sprite_pos);
	else if (w->map[y][x] == 'F')
		print_sprite(w, w->sprites.enemy.ref, w->sprite_pos);
	return (0);
}

int	display_map(t_program *w)
{
	int	x;
	int	y;

	y = 0;
	w->sprite_pos.y = 0;
	while (y < w->map_size.y)
	{
		x = 0;
		w->sprite_pos.x = 0;
		while (x < w->map_size.x)
		{
			check_print(x, y, w);
			x++;
			w->sprite_pos.x += w->sprites.wall.size.x;
		}
		y++;
		w->sprite_pos.y += w->sprites.wall.size.y;
	}
	return (0);
}
