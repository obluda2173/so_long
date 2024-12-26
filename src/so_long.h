/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:53:34 by erian             #+#    #+#             */
/*   Updated: 2024/12/10 14:23:20 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

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

/* ************************************************************************** */
/* error.c                                                                  * */
/* ************************************************************************** */
void	check_errors(t_complete *game);
/* ************************************************************************** */
/* graphics.c                                                               * */
/* ************************************************************************** */
void	place_images_in_game(t_complete *game);
void	adding_in_graphics(t_complete *game);
/* ************************************************************************** */
/* movement.c                                                               * */
/* ************************************************************************** */
int		controls(int command, t_complete *game);
/* ************************************************************************** */
/* parse.c                                                                  * */
/* ************************************************************************** */
int		map_reading(t_complete *game, char **argv);
/* ************************************************************************** */
/* so_long.c                                                                * */
/* ************************************************************************** */
char	**copy_map(char **map, int height);
void	exit_point_with_cleanup(t_complete *game, char **temp_map);
int		exit_point(t_complete *game);
int		main(int argc, char **argv);

#endif