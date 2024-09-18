/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:55:38 by erian             #+#    #+#             */
/*   Updated: 2024/09/18 18:07:18 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("You have won!\n");
		exit_point(game);
	}
	else if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	else if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == KEY_W)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == KEY_S)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j - 1][i] = '0';
	}
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == KEY_A)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == KEY_D)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		if (!right_move(game, i, j))
			return (0);
		game->map[j][i - 1] = '0';
	}
	return (1);
}

int	controls(int command, t_complete *game)
{
	int	works;

	works = 0;
	if (command == KEY_ESC)
		exit_point(game);
	else if (command == KEY_W || command == KEY_S)
	{
		works = keyboard_w_s(game, command);
		if (works)
			ft_printf("Steps Taken: %i\nCollectables Left: %i\n",
				game->counter, game->collectables);
	}
	else if (command == KEY_A || command == KEY_D)
	{
		works = keyboard_a_d(game, command);
		if (works)
			ft_printf("Steps Taken: %i\nCollectables Left: %i\n",
				game->counter, game->collectables);
	}
	if (works)
		adding_in_graphics(game);
	return (1);
}
