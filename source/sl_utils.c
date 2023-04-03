/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:21:39 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:21:42 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

char	*ft_free_join(char *str1, char *str2)
{
	char	*str;

	str = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str);
}

int	type_check(char *path)
{
	int	i;

	i = ft_strlen(path);
	i -= 4;
	return (ft_strncmp(&path[i], ".ber", 4));
}

int	ft_display_stats(t_program *w, int color)
{
	char	*str;
	char	*str2;

	str2 = ft_itoa(w->moves);
	str = ft_strjoin("Moves: ", str2);
	mlx_string_put(w->mlx, w->win.ref, 10, 12, color, str);
	free(str);
	free(str2);
	str2 = ft_itoa(w->c);
	str = ft_strjoin("Collectibles: ", str2);
	mlx_string_put(w->mlx, w->win.ref, 10, 27, color, str);
	free(str);
	free(str2);
	return (0);
}
