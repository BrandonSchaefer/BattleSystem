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

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Tile.h"
#include "Point.h"
#include "Direction.h"

namespace battle_system
{

class Grid
{
public:
  Grid(int col, int row, int size);

  int Rows() const;
  int Cols() const;

  void OpenAll();

  void OpenPassage(Point const& p, Direction const& dir);
  void OpenWall   (Point const& p, Direction const& dir);
  bool IsOpen     (Point const& p, Direction const& dir) const;

  SDL_Rect GetTileRect(Point const& p) const;

  Point GetTileIndexFromPointer(SDLBackend const& backend, Point const& mouse) const;

  // FIXME Remove me w/e debug purpose
  void print() const;

protected:
  bool InBounds(Point const& p) const;

  int const row_;
  int const col_;
  int const size_;

  std::vector<std::vector<Tile>> grid_;
};

} // namespace battle_system

#endif // GRID_H
