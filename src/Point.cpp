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

#include "Point.h"

namespace battle_system
{

static constexpr Point MoveRight(int x, int y, int offset = 1) { return {x,          y + offset}; }
static constexpr Point MoveLeft (int x, int y, int offset = 1) { return {x,          y - offset}; }
static constexpr Point MoveDown (int x, int y, int offset = 1) { return {x + offset, y}; }
static constexpr Point MoveUp   (int x, int y, int offset = 1) { return {x - offset, y}; }

Point Point::MoveDirection(Direction const& dir, int offset) const
{
  switch (dir)
  {
    case RIGHT:
      return MoveRight(x, y, offset);
    case DOWN:
      return MoveDown (x, y, offset);
    case LEFT:
      return MoveLeft (x, y, offset);
    case UP:
      return MoveUp   (x, y, offset);
    default:
      return {-1, -1};
  }
}

Point Point::Increment(int col, int row) const
{
  if (y + 1 >= row)
    return {x + 1, 0};

  return {x, y + 1};
}

bool Point::operator==(Point const& p) const
{
  return x == p.x && y == p.y;
}

bool Point::operator!=(Point const& p) const
{
  return !(*this == p);
}

} // namespace battle_system
