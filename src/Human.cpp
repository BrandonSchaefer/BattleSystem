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

#include "Human.h"

namespace battle_system
{

namespace
{
  int const BASE_HEIGHT =  60;
  int const BASE_WEIGHT = 140;
  int const BASE_AGE    =  15;

  // FIXME Subject to change... need to figure out how movement will work
  int const BASE_MOVE   = 12;

  std::string const RACE_NAME = "Human";
}

Human::Human(DiceFactory const& dice_factory)
{
  Dice height_mod = dice_factory.CreateDice(2, 10);
  Dice weight_mod = dice_factory.CreateDice(6, 10);
  Dice age_mod    = dice_factory.CreateDice(1, 4);

  height_ = height_mod.Roll(BASE_HEIGHT);
  weight_ = weight_mod.Roll(BASE_WEIGHT);
  age_    = age_mod.Roll(BASE_AGE);
}

int Human::BaseMove() const
{
  return BASE_MOVE;
}

std::string Human::RaceName() const
{
  return RACE_NAME;
}

} // namespace battle_system
