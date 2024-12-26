/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:58:26 by erian             #+#    #+#             */
/*   Updated: 2024/12/10 18:23:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	walls(t_complete *game)
{
	int	i;

	i = 0;
	while (i < game->heightmap)
	{
		if (!(game->map[i][0] == '1'
			&& game->map[i][game->widthmap - 1] == '1'))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->widthmap)
	{
		if (!(game->map[0][i] == '1'
			&& game->map[game->heightmap - 1][i] == '1'))
			return (0);
		i++;
	}
	return (1);
}

static void	count_checker(t_complete *game, char **temp_map,
							int height, int width)
{
	if (game->map[height][width] != '1'
		&& game->map[height][width] != '0'
		&& game->map[height][width] != 'P'
		&& game->map[height][width] != 'E'
		&& game->map[height][width] != 'C'
		&& game->map[height][width] != '\n')
	{
		ft_printf("Error\nInvalid character: %c\n", game->map[height][width]);
		exit_point_with_cleanup(game, temp_map);
	}
	if (game->map[height][width] == 'P')
	{
		game->playercount++;
		game->y_axis = height;
		game->x_axis = width;
	}
	if (game->map[height][width] == 'C')
		game->collectable_init++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

static void	character(t_complete *game, char **temp_map)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			count_checker(game, temp_map, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1
			&& game->exitcount == 1 && game->collectable_init >= 1))
	{
		ft_printf("Error\nInvalid map\n");
		exit_point_with_cleanup(game, temp_map);
	}
}

static void	flood_fill(t_complete *game, char **temp_map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->widthmap || y >= game->heightmap)
		return ;
	if (temp_map[y][x] == '1')
		return ;
	if (temp_map[y][x] == 'E')
	{
		game->exitcount = 2;
		return ;
	}
	else if (temp_map[y][x] == 'C')
		game->collectables++;
	temp_map[y][x] = '1';
	flood_fill(game, temp_map, x, y + 1);
	flood_fill(game, temp_map, x, y - 1);
	flood_fill(game, temp_map, x + 1, y);
	flood_fill(game, temp_map, x - 1, y);
}

void	check_errors(t_complete *game)
{
	char	**temp_map;
	int		x;
	int		y;
	int		i;

	temp_map = copy_map(game->map, game->heightmap);
	i = 0;
	if (!walls(game))
	{
		ft_printf("Error\nThis map is missing the walls\n");
		exit_point_with_cleanup(game, temp_map);
	}
	character(game, temp_map);
	x = game->x_axis;
	y = game->y_axis;
	flood_fill(game, temp_map, x, y);
	while (i < game->heightmap)
		free(temp_map[i++]);
	free(temp_map);
	if (!(game->collectable_init == game->collectables && game->exitcount == 2))
	{
		ft_printf("Error\nInvalid map\n");
		exit_point_with_cleanup(game, NULL);
	}
}
