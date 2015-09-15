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

#ifndef DICE
#define DICE

#include "RandomNumberGenerator.h"

namespace battle_system
{

struct DiceType
{
  int rolls;
  int die;
  int mod;
};

class Dice
{
public:
  Dice(RandomNumberGenerator::Ptr const& num_gen, DiceType const& settings);

  int Die()   const;
  int Rolls() const;
  int Mod()   const;
  int Roll(int mod = 0);

private:
  RandomNumberGenerator::Ptr num_gen_;
  int rolls_;
  int die_;
  int mod_;
};

} // namespace battle_system

#endif // DICE
