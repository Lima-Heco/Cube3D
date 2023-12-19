/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheinric <lheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:01:01 by lheinric          #+#    #+#             */
/*   Updated: 2023/12/04 17:09:59 by lheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	open_map(char *file, t_3d *t)
{
	char *map;
	int	tempx;

	map = (char *)ft_calloc(1001, sizeof(char));
	read(open(file, O_RDONLY), map, 1000);
	if (map[0] == '\0')
		return 0;
	t->map = ft_split(map, '\n');
	t->my = 0;
	t->mx = 0;
	while(t->map[t->my] != NULL)
	{
		tempx = 0;
		while(t->map[t->my][tempx] != '\0')
		{
			if(t->map[t->my][tempx] == 'N')
			{
				t->playerx = tempx * 32 + 16;
				t->playery = t->my * 32 + 16;
			}
			tempx++;

		}
		if(tempx > t->mx)
			t->mx = tempx;
		t->my++;
	}
	return 1;
}