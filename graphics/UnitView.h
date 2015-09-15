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

#ifndef UNIT_VIEW_H
#define UNIT_VIEW_H

#include "Point.h"
#include "SDLBackend.h"

#include <SDL2/SDL.h>

#include <queue>

namespace battle_system
{

class UnitView
{
public:
  UnitView(Point const& pos, int size);

  void Update(float delta_time);
  void Draw(SDLBackend const& backend) const;

  Point Position() const { return current_pos_; }

  bool IsMoving() const;

  void SetTileOffset(int offset);

  void MoveDirection(Direction const& d);
  void CancelMovementQueue();

private:
  Point current_pos_;
  Point next_pos_;
  int   size_;
  int   tile_offset_;

  std::queue<Direction> move_queue_;
};

} // namespace battle_system

#endif // UNIT_VIEW_H
