/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:30:40 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:30:43 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

static int	ft_event_check(char next_pos, t_program *w)
{
	if (next_pos == 'F')
	{
		write(1, "\nGAME OVER!\n", 12);
		ft_close(w);
	}
	if (next_pos == 'E')
	{
		write(1, "\nVICTORY!\n", 10);
		ft_close(w);
	}
	if (next_pos == 'C')
		w->c++;
	return (0);
}

static int	ft_update_stats(t_program *w)
{
	ft_display_stats(w, 0xFFFFFF);
	ft_printf("\rMoves = %d", w->moves);
	ft_printf("\tCollectibles = %d", w->c);
	return (0);
}

static int	ft_events(char next_pos, int x, int y, t_program *w)
{
	if (next_pos == '0' || next_pos == 'C' || next_pos == 'F'
		|| (next_pos == 'E' && w->c == w->coll))
	{
		ft_display_stats(w, 0x000000);
		w->moves++;
		ft_event_check(next_pos, w);
		ft_update_stats(w);
		w->map[y][x] = 'P';
		w->map[w->hero_pos.y][w->hero_pos.x] = '0';
		print_sprite(w, w->sprites.floor.ref,
			(t_vector){w->sprites.wall.size.x * w->hero_pos.x,
			w->sprites.wall.size.y * w->hero_pos.y});
		w->hero_pos.x = x;
		w->hero_pos.y = y;
		print_sprite(w, w->sprites.hero.ref,
			(t_vector){w->sprites.wall.size.x * w->hero_pos.x,
			w->sprites.wall.size.y * w->hero_pos.y});
	}
	return (0);
}

int	deal_key(int tasto, t_program *w)
{
	if (tasto == 65307)
		ft_close(w);
	else if (tasto == 'w' || tasto == 65362)
		ft_events(w->map[w->hero_pos.y - 1][w->hero_pos.x],
			w->hero_pos.x, w->hero_pos.y - 1, w);
	else if (tasto == 'a' || tasto == 65361)
		ft_events(w->map[w->hero_pos.y][w->hero_pos.x - 1],
			w->hero_pos.x - 1, w->hero_pos.y, w);
	else if (tasto == 's' || tasto == 65364)
		ft_events(w->map[w->hero_pos.y + 1][w->hero_pos.x],
			w->hero_pos.x, w->hero_pos.y + 1, w);
	else if (tasto == 'd' || tasto == 65363)
		ft_events(w->map[w->hero_pos.y][w->hero_pos.x + 1],
			w->hero_pos.x + 1, w->hero_pos.y, w);
	return (0);
}
