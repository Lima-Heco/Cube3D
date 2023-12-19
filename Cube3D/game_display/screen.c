/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheinric <lheinric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:01:39 by lheinric          #+#    #+#             */
/*   Updated: 2023/12/19 12:40:33 by lheinric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

#define GridSize 32
#define GridHeight 32

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void	calculatehorwall(t_3d *t, double *x, double *y, double alpha)
{
	if ((t->axe >= 170 && t->axe <= 190) || (t->axe >= 0 && t->axe <= 10) || (t->axe >= 350 && t->axe <= 360))
	{
		*x = 1000000000.0;
		*y = 1000000000.0;
		return;
	}
	int ray_up = ((t->axe >= 0) && (t->axe <= 180)? 0 : 1);
	double A_y = (int)(t->playery / GridSize) * GridSize - 1 + ray_up * GridSize;
	double A_x = t->playerx + (t->playery - A_y) / tan(alpha);
	*x = A_x;
	*y = A_y;
	/*while(t->map[(int)(*y / GridSize)][(int)(*x / GridSize)] != '1')
	{
		if ((t->axe >= 178 && t->axe <= 182) || (t->axe >= -2 && t->axe <= 6))
			break;
		double Ya = (ray_up ? -GridSize : GridSize);
		double Xa = GridSize / tan(alpha);

		*x += Xa;
		*y += Ya;
	}*/
}


void	calculateverwall(t_3d *t, double *x, double *y, double alpha)
{
	if ((t->axe >= 80 && t->axe <= 102) || (t->axe >= 258 && t->axe <= 282))
	{
		*x = 1000000000.0;
		*y = 1000000000.0;
		return;
	}
	int ray_right = ((t->axe >= 90) && (t->axe < 270)? 0 : 1);
	double B_x = (int)(t->playerx / GridSize) * GridSize + ray_right * GridSize;
	double B_y = t->playery + (t->playerx - B_x) * tan(alpha);
	*x = B_x;
	*y = B_y;
	/*while(t->map[(int)(*y / GridSize)][(int)(*x / GridSize)] != '1')
	{
		if(!ray_right && t->map[(int)(*y / GridSize) + 1][(int)(*x / GridSize) + 1] != '1')
			break;
		printf("	ok\n");
		double Xb = (ray_right ? GridSize : -GridSize);
		double Yb = GridSize * tan(alpha);

		*x += Xb;
		*y += Yb;
	}*/
}

void calculateIntersections(t_3d *t)
{
	//double PlayerPtX = t->playerx;  // Position du joueur en X
    //double PlayerPtY = t->playery;  // Position du joueur en Y
    double AngleDeVision = t->axe;
	double wallax = t->playerx;
	double wallay = t->playery;
	double wallbx = t->playerx;
	double wallby = t->playery;
	double alpha = AngleDeVision * M_PI / 180.0;
	double PB = 0;
	double PA = 0;
	double distanceIncorrecte = 0;

	//int ray_up = ((t->axe >= 0) && (t->axe <= 180)? 1 : 0);
	calculatehorwall(t, &wallax, &wallay, alpha);
	//double A_y = (int)(t->playery / GridSize) * GridSize - 1 + ray_up * GridSize;
	//double A_x = t->playerx + (t->playery - A_y) / tan(alpha);
	//double Ya = (ray_up ? -GridSize : GridSize);
	//double Xa = GridSize / tan(alpha);
	

	//int ray_right = ((t->axe >= 90) && (t->axe <= 270)? 1 : 0);
	calculateverwall(t, &wallbx, &wallby, alpha);
    //double B_x = (int)(t->playerx / GridSize) * GridSize + ray_right * GridSize;
	//double B_y = t->playery + (t->playerx - B_x) * tan(alpha);
	//double Xb = (ray_right ? GridSize : -GridSize);
	//double Yb = GridSize * tan(alpha);

	printf("point a = %f,%f\npoint b = %f,%f\nalpha = %f\n", wallax ,wallay ,wallbx ,wallby, t->axe);
	if((t->axe >= 90 && t->axe < 170) || t->axe  == 180)
	{
		PA = fabs(t->playerx - wallax) / sin(alpha) ;
		PB = fabs(t->playerx - wallbx) / sin(alpha) ;
	}
	else if (t->axe >= 170 && t->axe <= 180)
	{
		PA = fabs(t->playerx - wallax) / sin(alpha) ;
		PB = fabs(t->playerx - wallbx) / sin(alpha) ;
	}
	else if (t->axe > 180 && t->axe <= 270)
	{
		PA = fabs(t->playerx - wallax) / tan(alpha) ;
		PB = fabs(t->playerx - wallbx) / tan(alpha) ;
	}
	else
	{
		PA = fabs(t->playerx - wallax) / cos(alpha) ;
		PB = fabs(t->playerx - wallbx) / cos(alpha) ;
	}
	printf("PA = %f\nPB = %f\n", PA, PB);
	if (PA >= 0 && PB >= 0)
    	distanceIncorrecte = (PA < PB) ? PA : PB;
	else
		distanceIncorrecte = (PA < PB) ? -PA : -PB;
	if (distanceIncorrecte == PA && (wallax != t->playerx))
	{
		t->player_viewx = wallax;
		t->player_viewy = wallay;
	}
	if (distanceIncorrecte == PB && (wallbx != t->playerx && wallby))
	{
		t->player_viewx = wallbx;
		t->player_viewy = wallby;
	}
   // double beta = (ray_right ? -30.0 : 30.0);
   // double correcteDistance = distanceIncorrecte * cos(beta);
}

void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_circle(void *mlx_ptr, void *win_ptr, int center_x, int center_y, int radius)
{
    int x, y;
    int color = 0xFFFFFF; // Couleur blanche, vous pouvez changer cela si nécessaire

    for (int angle = 0; angle < 360; angle++)
    {
        // Convertir l'angle en radians
        float radians = angle * M_PI / 180.0;

        // Calculer les coordonnées du point sur le cercle
        x = center_x + radius * cos(radians);
        y = center_y + radius * sin(radians);

        // Dessiner le pixel à ces coordonnées
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
    }
}

void	put_wall(int i, int j, t_3d *t)
{
	int	k;
	int l;

	k = 0;
	l = 0;
	while(k != 32)
	{
		l = 0;
		while(l != 32)
		{
			mlx_pixel_put(t->mlx_ptr, t->mlx_win, ((j*32) + l), ((i*32) + k),  0x00FF00);
			l++;
		}
		k++;
	}
}

void	put_floor(int i, int j, t_3d *t)
{
	int	k;
	int l;

	k = 0;
	l = 0;
	while(k != 32)
	{
		l = 0;
		while(l != 32)
		{
			mlx_pixel_put(t->mlx_ptr, t->mlx_win, ((j*32) + l), ((i*32) + k),  0x000000);
			l++;
		}
		k++;
	}
}

void	put_player(t_3d *t)
{
	int	k;
	int l;

	calculateIntersections(t);
	k = 0;
	while(k != 32)
	{
		l = 0;
		while(l != 32)
		{
			mlx_pixel_put(t->mlx_ptr, t->mlx_win, ((t->playerx - 16) + l), ((t->playery - 16) + k),  0x000000);
			l++;
		}
		k++;
	}
	draw_circle(t->mlx_ptr, t->mlx_win, t->playerx, t->playery, 10);
	draw_line(t->mlx_ptr, t->mlx_win, t->playerx, t->playery, t->player_viewx, t->player_viewy, 0xFFFFFF);
}

void	minimap(t_3d *t)
{
	int	i;
	int	j;

	i = 0;
	while(t->map[i] != NULL)
	{
		j = 0;
		while(t->map[i][j])
		{
			if(t->map[i][j] == '1')
				put_wall(i, j, t);
			if(t->map[i][j] == '0')
				put_floor(i, j, t);
			j++;
		}
		i++;
	}
	put_player(t);
}


int	end(t_3d *t)
{
	mlx_clear_window(t->mlx_ptr, t->mlx_win);
	mlx_loop_end(t->mlx_ptr);
	mlx_destroy_window(t->mlx_ptr, t->mlx_win);
	t->mlx_ptr = NULL;
	return (0);
}

int key_hook(int keycode, t_3d *t)
{
	if (keycode == 100)
	{
		t->axe -= 2;
		if (t->axe == -2)
			t->axe = 358;
	}
	if (keycode == 113)
	{
		t->axe += 2;
		if (t->axe == 360)
			t->axe = 0;
	}
    printf("Touche pressée : %d\n", keycode);
	minimap(t);
    return 0;
}

void	start_display(t_3d *t)
{
		t->mlx_win = mlx_new_window(t->mlx_ptr, t->mx * 32, t->my * 32, "Cube3D");
		minimap(t);
		mlx_hook(t->mlx_win, 17, 0, end, t);
		mlx_key_hook(t->mlx_win, key_hook, t);
		mlx_loop(t->mlx_ptr);
		if (t->mlx_ptr != NULL)
			end(t);
}