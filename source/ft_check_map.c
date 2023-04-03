/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:28:28 by lamici            #+#    #+#             */
/*   Updated: 2022/12/20 09:33:48 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

static int	ft_square_check(char **map)
{
	int	check;
	int	y;

	y = 0;
	check = 0;
	while (map[y] && check == 0)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			check = 1;
		y++;
	}
	return (check);
}

static int	ft_wall_check(char **map, int xmax, int ymax)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	if (map)
	{
		while (i < ymax && check == 0)
		{
			if (map[i][0] != '1' || map[i][xmax - 1] != '1')
				check = 1;
			i++;
		}
		i = 0;
		while (i < xmax && check == 0)
		{
			if (map[0][i] != '1' || map[ymax - 1][i] != '1')
				check = 1;
			i++;
		}
	}
	return (check);
}

static int	ft_char_check(t_program *w)
{
	int	check;
	int	x;
	int	y;

	w->coll = 0;
	check = 1;
	y = 0;
	while (w->map[y] != 0)
	{
		x = 0;
		while (w->map[y][x] != '\0')
		{
			if (w->map[y][x] == 'C')
				w->coll++;
			else if (w->map[y][x] == 'P')
				check += 2;
			else if (w->map[y][x] == 'E')
				check += 3;
			x++;
		}
		y++;
	}
	if (check == 6 && w->coll >= 1)
		check = 0;
	return (check);
}

static int	ft_path_check(t_program *w)
{
	int	res;
	int	check;

	w->hero_pos.y = 0;
	check = 0;
	while (w->map[w->hero_pos.y] != 0 && check == 0)
	{
		w->hero_pos.x = 0;
		while (w->map[w->hero_pos.y][w->hero_pos.x] != '\0' && check == 0)
		{
			if (w->map[w->hero_pos.y][w->hero_pos.x] == 'P')
				check = 1;
			else
				w->hero_pos.x++;
		}
		if (!check)
			w->hero_pos.y++;
	}
	res = flood_fill(w->map, w->map_size, w->hero_pos);
	return (res);
}

int	ft_map_check(char *path, t_program *w)
{
	int	err;
	int	check;

	if (!type_check(path))
	{
		check = map_reader(path, w);
		err = 0;
		if (check == -1)
			err = ft_printf("Error\nMap does not exist.\n");
		else
		{
			if (ft_square_check(w->map) != 0)
				err = ft_printf("Error\nMap is not rectangular.\n");
			if (ft_wall_check(w->map, w->map_size.x, w->map_size.y) != 0)
				err = ft_printf("Error\nMap is not surrounded by walls.\n");
			if (ft_char_check(w))
				err = ft_printf("Error\nInvalid number of elements.\n");
			if (ft_path_check(w))
				err = ft_printf("Error\nThe exit is unreachable.\n");
			free_map(w->map);
		}
	}
	else
		err = ft_printf("Error\nIncompatible file type.\n");
	return (err);
}
