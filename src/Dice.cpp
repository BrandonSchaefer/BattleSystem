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

#include "Dice.h"

namespace battle_system
{

Dice::Dice(RandomNumberGenerator::Ptr const& num_gen, DiceType const& type)
  : num_gen_(num_gen)
  , rolls_(type.rolls)
  , die_  (type.die)
  , mod_  (type.mod)
{
}

int Dice::Die() const
{
  return die_;
}

int Dice::Rolls() const
{
  return rolls_;
}

int Dice::Mod() const
{
  return mod_;
}

int Dice::Roll(int mod)
{
  int roll = 0;

  for (int i = 0; i < rolls_; i++)
    roll += num_gen_->Generate(1, die_);

  return roll + mod;
}

} // namespace battle_system
