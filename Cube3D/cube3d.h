#ifndef CUBE3D_H
# define CUBE3D_H

#include <sys/stat.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//----------------------------------------
#include "./libft/libft.h"
#include "./mlx/mlx.h"

typedef struct s_mygame
{
	//screen_size_(axe)
	int	ss_x;
	int ss_y;
	//reset screen ?
	int	res;
	//exit request
	int	ex;
	//mlx
	void	*mlx_ptr;
	void	*mlx_win;
	//mlx img
	void	*menu;
}	t_3d;

//-------------------------------------------------
//startgame

int	open_map(char *file, t_3d *t);
void	start_display(t_3d *t);


#endif