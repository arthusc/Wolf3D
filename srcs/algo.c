/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achambon <achambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 20:01:51 by achambon          #+#    #+#             */
/*   Updated: 2017/10/13 22:23:39 by achambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <time.h>

void      calculate_distance_height_pixel(t_mlx *mlx, int x)
{
      if (mlx->side == 0)
          mlx->perpWallDist = (mlx->mapX - mlx->rayPosX + (1 - mlx->stepX) / 2) / mlx->rayDirX;
      else
          mlx->perpWallDist = (mlx->mapY - mlx->rayPosY + (1 - mlx->stepY) / 2) / mlx->rayDirY; 
      mlx->lineHeight = (int)(HEIGHT / mlx->perpWallDist);
      mlx->drawStart = -mlx->lineHeight / 2 + HEIGHT / 2;
      if(mlx->drawStart < 0)
          mlx->drawStart = 0;
      mlx->drawEnd = mlx->lineHeight / 2 + HEIGHT / 2;
      if(mlx->drawEnd >= HEIGHT)
          mlx->drawEnd = HEIGHT - 1;
      rt_colors(mlx, x);
    mlx->oldTime = mlx->time;
    mlx->time = clock();
    mlx->frameTime = (mlx->time - mlx->oldTime) / 1000.0;
    mlx->moveSpeed = mlx->frameTime * 5.0;
    mlx->rotSpeed = mlx->frameTime * 3.0;
}

void      digital_differential_analysis(t_mlx *mlx)
{
      while (mlx->hit == 0)
      {
        if (mlx->sideDistX < mlx->sideDistY)
        {
          mlx->sideDistX += mlx->deltaDistX;
          mlx->mapX += mlx->stepX;
          mlx->side = 0;
        }
        else
        {
          mlx->sideDistY += mlx->deltaDistY;
          mlx->mapY += mlx->stepY;
          mlx->side = 1;
        }
        if (mlx->map[mlx->mapX][mlx->mapY] > 0)
            mlx->hit = 1;
      }
      if (mlx->side == 0)
          mlx->perpWallDist = (mlx->mapX - mlx->rayPosX + (1 - mlx->stepX) / 2) / mlx->rayDirX;
      else
          mlx->perpWallDist = (mlx->mapY - mlx->rayPosY + (1 - mlx->stepY) / 2) / mlx->rayDirY; 
}

void      loop_init(t_mlx *mlx, int x)
{
      mlx->cameraX = 2 * x / WIDTH - 1;
      mlx->rayPosX = mlx->posX;
      mlx->rayPosY = mlx->posY;
      mlx->rayDirX = mlx->dirX + mlx->planeX * mlx->cameraX;
      mlx->rayDirY = mlx->dirY + mlx->planeY * mlx->cameraX;
      mlx->mapX = mlx->rayPosX;
      mlx->mapY = mlx->rayPosY;
      mlx->deltaDistX = sqrt(1 + (mlx->rayDirY * mlx->rayDirY) / (mlx->rayDirX * mlx->rayDirX));
      mlx->deltaDistY = sqrt(1 + (mlx->rayDirX * mlx->rayDirX) / (mlx->rayDirY * mlx->rayDirY));
      mlx->hit = 0;
      mlx->side = 0;
      if (mlx->rayDirX < 0)
      {
        mlx->stepX = -1;
        mlx->sideDistX = (mlx->rayPosX - mlx->mapX) * mlx->deltaDistX;
      }
      else
      {
        mlx->stepX = 1;
        mlx->sideDistX = (mlx->mapX + 1.0 - mlx->rayPosX) * mlx->deltaDistX;
      }
      if (mlx->rayDirY < 0)
      {
        mlx->stepY = -1;
        mlx->sideDistY = (mlx->rayPosY - mlx->mapY) * mlx->deltaDistY;
      }
      else
      {
        mlx->stepY = 1;
        mlx->sideDistY = (mlx->mapY + 1.0 - mlx->rayPosY) * mlx->deltaDistY;
      }
}

void      algo(t_mlx *mlx)
{
  int x;

  x = 0;
  while (x < WIDTH)
    {
      loop_init(mlx, x);
      // mlx->cameraX = 2 * x / WIDTH - 1;
      // mlx->rayPosX = mlx->posX;
      // mlx->rayPosY = mlx->posY;
      // mlx->rayDirX = mlx->dirX + mlx->planeX * mlx->cameraX;
      // mlx->rayDirY = mlx->dirY + mlx->planeY * mlx->cameraX;
      // mlx->mapX = mlx->rayPosX;
      // mlx->mapY = mlx->rayPosY;
      // mlx->deltaDistX = sqrt(1 + (mlx->rayDirY * mlx->rayDirY) / (mlx->rayDirX * mlx->rayDirX));
      // mlx->deltaDistY = sqrt(1 + (mlx->rayDirX * mlx->rayDirX) / (mlx->rayDirY * mlx->rayDirY));
      // mlx->hit = 0;
      // mlx->side = 0;
      // if (mlx->rayDirX < 0)
      // {
      //   mlx->stepX = -1;
      //   mlx->sideDistX = (mlx->rayPosX - mlx->mapX) * mlx->deltaDistX;
      // }
      // else
      // {
      //   mlx->stepX = 1;
      //   mlx->sideDistX = (mlx->mapX + 1.0 - mlx->rayPosX) * mlx->deltaDistX;
      // }
      // if (mlx->rayDirY < 0)
      // {
      //   mlx->stepY = -1;
      //   mlx->sideDistY = (mlx->rayPosY - mlx->mapY) * mlx->deltaDistY;
      // }
      // else
      // {
      //   mlx->stepY = 1;
      //   mlx->sideDistY = (mlx->mapY + 1.0 - mlx->rayPosY) * mlx->deltaDistY;
      // }
      digital_differential_analysis(mlx);     
      calculate_distance_height_pixel(mlx, x);
      x++;
  	}
}