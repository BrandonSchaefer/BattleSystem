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

#include "PathFinder.h"

namespace battle_system
{

std::vector<Direction> FindPath(BattleGrid const& grid, Point const& start, Point const& end)
{
  std::vector<Direction> path;

  Point current = start;

  while (current != end)
  {
    if (current.x > end.x)
    {
      current.x--;
      path.push_back(UP);
    }
    else if (current.x < end.x)
    {
      current.x++;
      path.push_back(DOWN);
    }

    if (current.y > end.y)
    {
      current.y--;
      path.push_back(LEFT);
    }
    else if (current.y < end.y)
    {
      current.y++;
      path.push_back(RIGHT);
    }
  }

  return path;
}

} // namespace battle_system
