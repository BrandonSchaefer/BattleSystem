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

#include "SDLBackend.h"

#include <stdexcept>

namespace battle_system
{

SDLBackend::SDLBackend(SDLBackendSettings const& settings)
  : camera_({settings.camera_x, settings.camera_y, settings.width, settings.height})
  , width_ (settings.width)
  , height_(settings.height)
  , world_width_ (settings.world_width)
  , world_height_(settings.world_height)
  , title_ (settings.title)
{
  InitSDL();
  CreateWindow();
  CreateRenderer();
}

SDLBackend::~SDLBackend()
{
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow  (window_);

  //IMG_Quit();
  //TTF_Quit();
  SDL_Quit();
}

void SDLBackend::InitSDL()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    throw std::runtime_error("Failed to INIT SDL");

  //if (IMG_Init(IMG_INIT_PNG) < 0)
    //throw std::runtime_error("Failed to INIT IMG");

  //if (TTF_Init() < 0)
    //throw std::runtime_error("Failed to INIT TTF");
}

void SDLBackend::CreateWindow()
{
  window_ = SDL_CreateWindow(title_.c_str(),
                             SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED,
                             width_, height_, SDL_WINDOW_SHOWN);

  if (!window_)
    throw std::runtime_error("Failed to create SDL_Window");
}

void SDLBackend::CreateRenderer()
{
  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer_)
    throw std::runtime_error("Failed to create SDL_Renderer");
}

void SDLBackend::MoveCameraRight(int amount)
{
  if (camera_.x + amount + camera_.w > world_width_)
    camera_.x = world_width_ - width_;
  else
    camera_.x += amount;
}

void SDLBackend::MoveCameraLeft(int amount)
{
  if (camera_.x - amount <= 0)
    camera_.x = 0;
  else
    camera_.x -= amount;
}

void SDLBackend::MoveCameraDown(int amount)
{
  if (camera_.y + amount + camera_.h > world_height_)
    camera_.y = world_height_ - height_;
  else
    camera_.y += amount;
}

void SDLBackend::MoveCameraUp(int amount)
{
  if (camera_.y - amount <= 0)
    camera_.y = 0;
  else
    camera_.y -= amount;
}

// x - y,        iso_x
// (x + y) / 2,  iso_y

SDL_Rect SDLBackend::ApplyCameraOffset(SDL_Rect const& dest) const
{
  int x = dest.x - camera_.x;
  int y = dest.y - camera_.y;

  return {x, y, dest.w, dest.h};
}

SDL_Window* SDLBackend::GetWindow() const
{
  return window_;
}

SDL_Renderer* SDLBackend::GetRenderer() const
{
  return renderer_;
}

} // namespace battle_system
