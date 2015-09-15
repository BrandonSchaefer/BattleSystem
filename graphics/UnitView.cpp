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

#include "UnitView.h"

#include <iostream>

namespace battle_system
{

namespace
{
  int const MOVE = 3;
}

UnitView::UnitView(Point const& pos, int size)
  : current_pos_(pos)
  , next_pos_   ({pos.x, pos.y})
  , size_(size)
{
}

bool UnitView::IsMoving() const
{
  return current_pos_ != next_pos_;
}

void UnitView::Update(float delta_time)
{
  if (IsMoving())
  {
    if (next_pos_.x > current_pos_.x)
      current_pos_.x += MOVE;
    else if (next_pos_.x < current_pos_.x)
      current_pos_.x -= MOVE;
    if (next_pos_.y > current_pos_.y)
      current_pos_.y += MOVE;
    else if (next_pos_.y < current_pos_.y)
      current_pos_.y -= MOVE;

    if (std::abs(next_pos_.x - current_pos_.x) < MOVE)
      current_pos_.x = next_pos_.x;
    if (std::abs(next_pos_.y - current_pos_.y) < MOVE)
      current_pos_.y = next_pos_.y;

  }
  else if (!move_queue_.empty())
  {
    Direction d = move_queue_.front();
    move_queue_.pop();
    MoveDirection(d);
  }
}

void UnitView::SetTileOffset(int offset)
{
  tile_offset_ = offset;
}

void UnitView::CancelMovementQueue()
{
  move_queue_ = std::queue<Direction>();
}

void UnitView::MoveDirection(Direction const& d)
{
  if (IsMoving())
    move_queue_.push(d);
  else
  {
    // move to function
    switch (d)
    {
      case RIGHT:
        next_pos_.x += tile_offset_;
        break;
      case LEFT:
        next_pos_.x -= tile_offset_;
        break;
      case DOWN:
        next_pos_.y += tile_offset_;
        break;
      case UP:
        next_pos_.y -= tile_offset_;
        break;
      default:
        break;
    }
  }
}

void UnitView::Draw(SDLBackend const& backend) const
{
  SDL_SetRenderDrawColor(backend.GetRenderer(), 0x00, 0xFF, 0x00, 0xFF);
  SDL_Rect dest = backend.ApplyCameraOffset({current_pos_.x, current_pos_.y, size_, size_});
  SDL_RenderFillRect(backend.GetRenderer(), &dest);
}

} // namespace battle_system
