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

#include "Class.h"

#include <iostream>

namespace battle_system
{

namespace
{
  int const MAX_LEVEL         = 20;
}

Class::Class(Dice const& hit_dice)
  : health_    (0)
  , level_     (0)
  , hit_dice_  (hit_dice)
{
}

void Class::LevelUp(CharacterStats const& stats)
{
  int con_bonus = ConstitutionHPBonus(stats);
  level_++;

  if (level_ <= MaxHitDiceLevel())
    health_ += hit_dice_.Roll(con_bonus);
  else
    health_ += ConstLifeAfterMaxDiceLevel() + con_bonus;
}

int Class::Health() const
{
  return health_;
}

int Class::Level() const
{
  return level_;
}

} // namespace battle_system
