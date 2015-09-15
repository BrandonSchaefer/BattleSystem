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

#ifndef TILE_H
#define TILE_H

#include "Direction.h"
#include "SDLBackend.h"

#include <SDL2/SDL.h>

#include <vector>

namespace battle_system
{

class Tile
{
public:
  Tile();

  void OpenDirection  (Direction const& dir);
  bool IsDirectionOpen(Direction const& dir) const;
  //void CloseDirection (Direction const& dir);

  void SetRect(SDL_Rect const& rect);
  SDL_Rect GetRect() const;

  void Draw(SDLBackend const& backend) const;

  void test();

private:
  int test_;

  std::vector<bool> open_;

  SDL_Rect rect_;

};

} // namespace battle_system

#endif // TILE_H
