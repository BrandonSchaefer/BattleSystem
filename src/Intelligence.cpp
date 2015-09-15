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

#include "Intelligence.h"

namespace battle_system
{

namespace
{
  int const MIN_INT   =  9;
  int const MAX_INT   = 19;
  int const MAX_SPELL = 50;

  struct IntelligenceAbilities
  {
    int chance_to_learn;
    int max_spells_per_lvl;
  };

  static IntelligenceAbilities const intelligence_abilities[] = {
                                                                  {35, 6},         // 9
                                                                  {45, 7},         // 10
                                                                  {45, 7},         // 11
                                                                  {45, 7},         // 12
                                                                  {55, 9},         // 13
                                                                  {55, 9},         // 14
                                                                  {65, 11},        // 15
                                                                  {65, 11},        // 16
                                                                  {75, 14},        // 17
                                                                  {85, 18},        // 18
                                                                  {95, MAX_SPELL}, // 19
                                                                };
}

static IntelligenceAbilities GetIntelligenceAbility(int intelligence)
{
  if (intelligence >= MIN_INT && intelligence <= MAX_INT)
    return intelligence_abilities[intelligence - MIN_INT];

  return {0, 0};
}

Intelligence::Intelligence(int intelligence)
  : intelligence_(intelligence)
{
}

int Intelligence::GetIntelligence() const
{
  return intelligence_;
}

void Intelligence::SetIntelligence(int intelligence)
{
  intelligence_ = intelligence;
}

int Intelligence::ChanceToLearnSpell() const
{
  IntelligenceAbilities int_abi = GetIntelligenceAbility(intelligence_);

  return int_abi.chance_to_learn;
}

int Intelligence::MaxNumberOfSpellsPerLevel() const
{
  IntelligenceAbilities int_abi = GetIntelligenceAbility(intelligence_);

  return int_abi.max_spells_per_lvl;
}

} // namespace battle_system
