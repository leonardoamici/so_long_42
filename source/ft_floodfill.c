/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:14:12 by lamici            #+#    #+#             */
/*   Updated: 2022/12/20 09:05:57 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "../Libft/libft.h"

static void	ft_find(char **temp, t_vector size, t_vector pos)
{
	if (pos.x < 0 || pos.x > size.x || pos.y < 0 || pos.y >= size.y
		|| temp[pos.y][pos.x] == '1')
		return ;
	temp[pos.y][pos.x] = '1';
	ft_find(temp, size, (t_vector){pos.x + 1, pos.y});
	ft_find(temp, size, (t_vector){pos.x - 1, pos.y});
	ft_find(temp, size, (t_vector){pos.x, pos.y + 1});
	ft_find(temp, size, (t_vector){pos.x, pos.y - 1});
}

int	flood_fill(char **tab, t_vector size, t_vector begin)
{
	int	y;
	int	x;

	y = 0;
	ft_find(tab, size, begin);
	while (tab[y] != 0)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] != '0' && tab[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
