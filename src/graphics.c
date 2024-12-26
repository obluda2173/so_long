/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:24:42 by erian             #+#    #+#             */
/*   Updated: 2024/12/10 11:41:19 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_complete *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, x * 100, y * 100);
	else if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->collectable, x * 100, y * 100);
		game->collectables++;
	}
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player, x * 100, y * 100);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, x * 100, y * 100);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, x * 100, y * 100);
}

static void	render_row(t_complete *game, int height)
{
	int	width;

	width = 0;
	while (game->map[height][width])
	{
		put_image(game, width, height, game->map[height][width]);
		width++;
	}
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/character.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/item.xpm", &i, &j);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		render_row(game, height);
		height++;
	}
}
