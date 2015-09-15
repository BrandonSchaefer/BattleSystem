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

#include "Dexterity.h"

namespace battle_system
{

namespace
{
  int const MIN_DEX =  3;
  int const MAX_DEX = 18;

  struct DexterityAbilities
  {
    int ac_bonus;
  };

  static DexterityAbilities const dexterity_abilities[] = {
                                                           { 4},  // 3
                                                           { 3},  // 4
                                                           { 2},  // 5
                                                           { 1},  // 6
                                                           { 0},  // 7
                                                           { 0},  // 8
                                                           { 0},  // 9
                                                           { 0},  // 10
                                                           { 0},  // 11
                                                           { 0},  // 12
                                                           { 0},  // 13
                                                           { 0},  // 14
                                                           {-1},  // 15
                                                           {-2},  // 16
                                                           {-3},  // 17
                                                           {-4}   // 18
                                                        };
}

static DexterityAbilities GetDexterityAbility(int dexterity)
{
  if (dexterity >= MIN_DEX && dexterity <= MAX_DEX)
    return dexterity_abilities[dexterity - MIN_DEX];

  return {0};
}

Dexterity::Dexterity(int dexterity)
  : dexterity_(dexterity)
{
}

int Dexterity::GetDexterity() const
{
  return dexterity_;
}

void Dexterity::SetDexterity(int dexterity)
{
}

int Dexterity::ACBonus() const
{
  DexterityAbilities dex_abi = GetDexterityAbility(dexterity_);

  return dex_abi.ac_bonus;
}


} // namespace battle_system
