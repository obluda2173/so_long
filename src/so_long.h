/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:53:34 by erian             #+#    #+#             */
/*   Updated: 2024/09/18 11:58:14 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"

// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define KEY_ESC 65307

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		collectable_init;
	int		collectables;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
}				t_complete;

void	check_errors(t_complete *game);
int		map_reading(t_complete *game, char **argv);
void	place_images_in_game(t_complete *game);
void	adding_in_graphics(t_complete *game);
int		controls(int command, t_complete *game);
char	**copy_map(char **map, int height);
int		exit_point(t_complete *game);
int		main(int argc, char **argv);

#endif