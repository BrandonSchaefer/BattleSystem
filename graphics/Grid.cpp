//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2015 Brandon Schaefer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
*/

#include "Grid.h"

#include <stdio.h>
#include <unistd.h>

#include <iostream>

namespace battle_system
{
 
namespace
{
  Point    const ERROR_POINT{-1, -1};
  SDL_Rect const ERROR_RECT {-1, -1, -1, -1};
}

Grid::Grid(int col, int row, int size)
  : row_ (row)
  , col_ (col)
  , size_(size)
  , grid_(col, std::vector<Tile>(row))
{
  for (int i = 0; i < col_; i++)
  {
    for (int j = 0; j < row_; j++)
    {
      grid_[i][j].SetRect({(size + 1) * j, (size + 1) * i, size, size});
    }
  }

  grid_[1][3].test();

  OpenAll();
}

int Grid::Rows() const
{
  return row_;
}

int Grid::Cols() const
{
  return col_;
}

SDL_Rect Grid::GetTileRect(Point const& p) const
{
  if (InBounds(p))
    return grid_[p.x][p.y].GetRect();

  return ERROR_RECT;
}

// FIXME Move the camera out of the backend...
Point Grid::GetTileIndexFromPointer(SDLBackend const& backend, Point const& mouse) const
{
  for (int i = 0; i < col_; i++)
  {
    for (int j = 0; j < row_; j++)
    {
      SDL_Rect rect = backend.ApplyCameraOffset(GetTileRect({i, j}));

      if (mouse.x >= rect.x && mouse.x <= rect.x + rect.w &&
          mouse.y >= rect.y && mouse.y <= rect.y + rect.h)
      {
        return {i, j};
      }
    }
  }
  
  return ERROR_POINT;
}

bool Grid::InBounds(Point const& p) const
{
  return (p.x >= 0 && p.x < col_ &&
          p.y >= 0 && p.y < row_);
}

void Grid::OpenAll()
{
  for (int i = 0; i < col_; i++)
  {
    for (int j = 0; j < row_; j++)
    {
      for (int d = 1; d < Direction::Size; d++)
      {
        OpenPassage({i, j}, Direction(d));
      }
    }
  }
}

void Grid::OpenPassage(Point const& p, Direction const& dir)
{
  if (InBounds(p))
  {
    Direction opp_dir = Opposite(dir);
    Point p_o         = p.MoveDirection(dir);

    if (InBounds(p_o))
    {
      grid_[p.x  ][p.y  ].OpenDirection(dir);
      grid_[p_o.x][p_o.y].OpenDirection(opp_dir);
    }
  }
}

void Grid::OpenWall(Point const& p, Direction const& dir)
{
  if (InBounds(p))
    grid_[p.x][p.y].OpenDirection(dir);
}

bool Grid::IsOpen(Point const& p, Direction const& dir) const
{
  if (InBounds(p))
    return grid_[p.x][p.y].IsDirectionOpen(dir);

  return false;
}

void Grid::print() const
{
  usleep(1000 * 10);
  printf("\033[2J\033[1;1H");
  for (int i = 0; i < row_; i++)
    printf(" _");
  printf("\n");

  for (int i = 0; i < col_; i++)
  {
    printf("|");
    for (int j = 0; j < row_; j++)
    {
      if (grid_[i][j].IsDirectionOpen(Direction::DOWN))
        printf(" ");
      else
        printf("_");

      if (grid_[i][j].IsDirectionOpen(Direction::RIGHT))
        printf(" ");
      else
        printf("|");
    }
    printf("\n");
  }
}

} // namespace battle_system
