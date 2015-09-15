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

#include "BattleGrid.h"

namespace battle_system
{

BattleGrid::BattleGrid(int col, int row, int size)
  : Grid(col, row, size)
{
}

void BattleGrid::Draw(SDLBackend const& backend)
{
  for (auto const& row : grid_)
    for (auto const& tile : row)
      tile.Draw(backend);
}

void BattleGrid::MarkDimaondRadius(Point const& index, int radius)
{
  // First half
  for (int i = 0; i <= radius; i++)
  {
    for (int j = -i; j <= i; j++)
    {
      int x = index.x - radius + i;
      int y = index.y + j;

      if (InBounds({x, y}))
        grid_[x][y].test();
    }
  }

  // Second half
  for (int i = 0; i <= radius; i++)
  {
    for (int j = -radius + i; j <= radius - i; j++)
    {
      int x = index.x + i;
      int y = index.y + j;

      if (InBounds({x, y}))
        grid_[x][y].test();
    }
  }
}

void BattleGrid::MarkSquareRadius(Point const& index, int radius)
{
  for (int i = -radius; i <= radius; i++)
  {
    for (int j = -radius; j <= radius; j++)
    {
      int x = index.x + i;
      int y = index.y + j;

      if (InBounds({x, y}))
        grid_[x][y].test();
    }
  }
}

} // namespace battle_system
