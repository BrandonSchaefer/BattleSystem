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

#ifndef S_D_L_BACKEND_H
#define S_D_L_BACKEND_H

#include <SDL2/SDL.h>

#include <string>

namespace battle_system
{

struct SDLBackendSettings
{
  std::string title;
  int camera_x;
  int camera_y;
  int width;
  int height;
  int world_width;
  int world_height;
};

class SDLBackend
{
public:
  SDLBackend(SDLBackendSettings const& settings);
  ~SDLBackend();

  void MoveCameraRight(int amount);
  void MoveCameraLeft (int amount);
  void MoveCameraDown (int amount);
  void MoveCameraUp   (int amount);

  SDL_Rect ApplyCameraOffset(SDL_Rect const& dest) const;

  SDL_Window*   GetWindow()   const;
  SDL_Renderer* GetRenderer() const;

private:
  void InitSDL();
  void CreateWindow();
  void CreateRenderer();

  SDL_Window*   window_;
  SDL_Renderer* renderer_;

  SDL_Rect camera_;

  int width_;
  int height_;
  int world_width_;
  int world_height_;
  std::string title_;
};

} // namespace battle_system

#endif // S_D_L_BACKEND_H
