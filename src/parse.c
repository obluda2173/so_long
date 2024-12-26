/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:26:58 by erian             #+#    #+#             */
/*   Updated: 2024/12/10 18:23:29 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0')
		width++;
	if (line[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temp)
	{
		free(line);
		return (0);
	}
	temp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	readmap = get_next_line(game->fd);
	if (!readmap)
	{
		ft_printf("Error\nInvalid map\n");
		exit_point(game);
	}
	while (readmap != NULL)
	{
		if (!add_line(game, readmap))
		{
			ft_printf("Error\nMemory allocation failed\n");
			exit_point(game);
		}
		readmap = get_next_line(game->fd);
	}
	close(game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
