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

#include "Wisdom.h"

namespace battle_system
{

namespace
{
  int const MIN_WIS = 3;
  int const MAX_WIS = 18;

  struct WisdomAbilities
  {
    int saving_throw_bonus;
    std::vector<int> bonus_spells;
    int chance_spell_fail;
  };

  static WisdomAbilities const wisdom_abilities[] = {
                                                     {-3, {},                20}, // 3
                                                     {-2, {},                20}, // 4
                                                     {-1, {},                20}, // 5
                                                     {-1, {},                20}, // 6
                                                     {-1, {},                20}, // 7
                                                     { 0, {},                20}, // 8
                                                     { 0, {},                20}, // 9
                                                     { 0, {},                15}, // 10
                                                     { 0, {},                10}, // 11
                                                     { 0, {},                 5}, // 12
                                                     { 0, {1},                0}, // 13
                                                     { 0, {1, 1},             0}, // 14
                                                     { 1, {1, 1, 2},          0}, // 15
                                                     { 2, {1, 1, 2, 2},       0}, // 16
                                                     { 3, {1, 1, 2, 2, 4},    0}, // 17
                                                     { 4, {1, 1, 2, 2, 4, 4}, 0}, // 18
                                                  };
}

static WisdomAbilities GetWisdomAbility(int wisdom)
{
  if (wisdom >= MIN_WIS && wisdom >= MAX_WIS)
    return wisdom_abilities[wisdom - MIN_WIS];

  return {0, {}, 100};
}

Wisdom::Wisdom(int wisdom)
  : wisdom_(wisdom)
{
}

int Wisdom::GetWisdom() const
{
  return wisdom_;
}

void Wisdom::SetWisdom(int wisdom)
{
  wisdom_ = wisdom;
}

int Wisdom::SavingThrowBonus() const
{
  WisdomAbilities wis_abi = GetWisdomAbility(wisdom_);

  return wis_abi.saving_throw_bonus;
}

std::vector<int> Wisdom::BonusSpells() const
{
  WisdomAbilities wis_abi = GetWisdomAbility(wisdom_);

  return wis_abi.bonus_spells;
}

int Wisdom::ChanceOfFailure() const
{
  WisdomAbilities wis_abi = GetWisdomAbility(wisdom_);

  return wis_abi.chance_spell_fail;
}

} // namespace battle_system
