/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheinric <lheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:01:39 by lheinric          #+#    #+#             */
/*   Updated: 2023/11/29 13:07:26 by lheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	end(t_3d *t)
{
	mlx_clear_window(t->mlx_ptr, t->mlx_win);
	mlx_loop_end(t->mlx_ptr);
	mlx_destroy_window(t->mlx_ptr, t->mlx_win);
	t->mlx_ptr = NULL;
	return (0);
}

void	start_display(t_3d *t)
{
		t->mlx_win = mlx_new_window(t->mlx_ptr, t->ss_x, t->ss_y, "Cube3D");
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->menu, 0, 0);
		mlx_hook(t->mlx_win, 17, 0, end, t);
		mlx_loop(t->mlx_ptr);
		if (t->mlx_ptr != NULL)
			end(t);
}