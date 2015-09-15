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

#include "Tile.h"

namespace battle_system
{

Tile::Tile()
  : test_(0)
  , open_(Direction::Size)
  , rect_({0, 0, 0, 0})
{
}

void Tile::OpenDirection(Direction const& dir)
{
  open_[dir] = true;
}

bool Tile::IsDirectionOpen(Direction const& dir) const
{
  return open_[dir];
}

void Tile::SetRect(SDL_Rect const& rect)
{
  rect_ = rect;
}

SDL_Rect Tile::GetRect() const
{
  return rect_;
}

void Tile::test()
{
  test_ = 255;
}

void Tile::Draw(SDLBackend const& backend) const
{
  SDL_SetRenderDrawColor(backend.GetRenderer(), 0xFF, test_, 0x00, 0xFF);
  SDL_Rect dest = backend.ApplyCameraOffset(rect_);
  SDL_RenderFillRect(backend.GetRenderer(), &dest);
}

} // namespace battle_system
