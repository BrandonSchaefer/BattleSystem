#include "DiceFactory.h"
#include "Direction.h"

#include "BattleGrid.h"
#include "SDLBackend.h"
#include "SDLTimer.h"
#include "UnitView.h"

#include "PathFinder.h"

#include <iostream>

namespace bs = battle_system;

namespace
{
  int const CAMERA_X      = 0;
  int const CAMERA_Y      = 0;
  int const WIDTH         = 800;
  int const HEIGHT        = 600;
  std::string const TITLE = "BattleSystem";

  int const FRAMES_PER_SECOND = 60;
  float const ONE_SECOND      = 1000.0f;

  bs::SDLBackendSettings const settings = {TITLE, CAMERA_X, CAMERA_Y, WIDTH, HEIGHT, 900, 600};
}

int main()
{
  bs::SDLBackend backend(settings);
  bs::DiceFactory df;

  bs::UnitView view({27, 27}, 10);
  view.SetTileOffset(65);

  bool done = false;

  bs::BattleGrid grid(100, 150, 64);

  //std::vector<bs::Direction> solve = bs::FindPath(grid, {0, 0}, {4, 7});

  //std::cout << solve.size() << std::endl;

  //for (auto const& s : solve)
    //view.MoveDirection(s);

  grid.MarkDimaondRadius({3, 5}, 2);
  grid.MarkSquareRadius( {9, 5}, 2);

  float delta_time = 0.0f;
  bs::SDLTimer fps;

  while (!done)
  {
    fps.start();

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_KEYUP:
          if (event.key.keysym.sym == SDLK_RIGHT)
            backend.MoveCameraRight(5);
          else if (event.key.keysym.sym == SDLK_LEFT)
            backend.MoveCameraLeft(5);
          else if (event.key.keysym.sym == SDLK_DOWN)
            backend.MoveCameraDown(5);
          else if (event.key.keysym.sym == SDLK_UP)
            backend.MoveCameraUp(5);
          else if (event.key.keysym.sym == SDLK_w)
            view.MoveDirection(bs::UP);
          else if (event.key.keysym.sym == SDLK_a)
            view.MoveDirection(bs::LEFT);
          else if (event.key.keysym.sym == SDLK_s)
            view.MoveDirection(bs::DOWN);
          else if (event.key.keysym.sym == SDLK_d)
            view.MoveDirection(bs::RIGHT);
          else if (event.key.keysym.sym == SDLK_ESCAPE)
            done = true;
          break;
        case SDL_MOUSEBUTTONUP:
        {
          bs::Point index   = grid.GetTileIndexFromPointer(backend, {event.button.x, event.button.y});
          bs::Point p_index = grid.GetTileIndexFromPointer(backend, view.Position());
          std::cout << index.x << " " << index.y << " -- " << p_index.x << " " << p_index.y << std::endl;
          std::vector<bs::Direction> solve = bs::FindPath(grid, p_index, index);

          view.CancelMovementQueue();
          for (auto const& s : solve)
            view.MoveDirection(s);
          std::cout << std::endl;
        }
          break;
        case SDL_MOUSEMOTION:
        {
          //bs::Point index   = grid.GetTileIndexFromPointer(backend, {event.button.x, event.button.y});

          //std::cout << "Motion (x,y) : (" << event.motion.x << "," << event.motion.y << ") " << std::endl;
          //std::cout << "  TileIndex (i, j) : (" << index.x << "," << index.y << ") " << std::endl;
        }
          break;
        case SDL_QUIT:
          done = true;
          break;
      }
    }

    SDL_RenderClear(backend.GetRenderer());

    //SDL_SetRenderDrawColor(backend.GetRenderer(), 0xFF, 0x00, 0x00, 0xFF);
    //SDL_Rect rect = {0 - camera.x, 0 - camera.y, 50, 100};
    //SDL_RenderFillRect(backend.GetRenderer(), &rect);

    view.Update(delta_time);

    grid.Draw(backend);
    view.Draw(backend);

    // Draw here
    SDL_SetRenderDrawColor(backend.GetRenderer(), 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderPresent(backend.GetRenderer());

    if (fps.ticks() < ONE_SECOND / FRAMES_PER_SECOND)
      SDL_Delay((ONE_SECOND / FRAMES_PER_SECOND) - fps.ticks());

    delta_time = fps.ticks() / ONE_SECOND;
  }

  //grid.print();
}
