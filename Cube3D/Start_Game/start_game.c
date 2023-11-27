/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheinric <lheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:37 by lheinric          #+#    #+#             */
/*   Updated: 2023/11/27 12:11:06 by lheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && open_map(argv[1]) > 0)
	{
		printf("map found");
	}
	else
		printf("ERROR: map not found");
	return (0);
}