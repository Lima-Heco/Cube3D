/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheinric <lheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:37 by lheinric          #+#    #+#             */
/*   Updated: 2023/11/29 13:06:22 by lheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	img_init(t_3d *t)
{
	t->menu = mlx_xpm_file_to_image(t->mlx_ptr, "assets/menu_assets/Doom-1.xpm", &t->ss_x, &t->ss_y);
	if (t->menu == NULL)
	{
		printf("NOK\n");
	}
	return 1;
}

int	game_init(t_3d *t)
{
	t->mlx_ptr = mlx_init();
	t->res = 0;
	img_init(t);
	start_display(t);
	while (t->res == 1)
		game_init(t);
	return 1;
}

int	main(int argc, char **argv)
{
	t_3d	*t;

	t = ft_calloc(1, sizeof(t_3d));
	t->ss_x = 1920;
	t->ss_y = 1080;
	if (argc == 2 && open_map(argv[1], t) > 0)
	{
		game_init(t);
	}
	else
		printf("Error:\n	map not found\n");
	return (0);
}