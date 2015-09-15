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

#include "Constitution.h"

namespace battle_system
{

namespace
{
  int const MIN_CON =  3;
  int const MAX_CON = 18;

  struct ConstitutionAbilities
  {
    int hp_bonus;
  };

  static ConstitutionAbilities const constitution_abilities[] = {
                                                                 {-2}, // 3
                                                                 {-1}, // 4
                                                                 {-1}, // 5
                                                                 {-1}, // 6
                                                                 { 0}, // 7
                                                                 { 0}, // 8
                                                                 { 0}, // 9
                                                                 { 0}, // 10
                                                                 { 0}, // 11
                                                                 { 0}, // 12
                                                                 { 0}, // 13
                                                                 { 0}, // 14
                                                                 { 1}, // 15
                                                                 { 2}, // 16
                                                                 { 3}, // 17
                                                                 { 4}  // 18
                                                              };
}

static ConstitutionAbilities GetConstitutionAbilities(int constitution)
{
  if (constitution >= MIN_CON && constitution <= MAX_CON)
    return constitution_abilities[constitution - MIN_CON];

  return {0};
}

Constitution::Constitution(int constitution)
  : constitution_(constitution)
{
}

int Constitution::GetConstitution() const
{
  return constitution_;
}

void Constitution::SetConstitution(int constitution)
{
  constitution_ = constitution;
}

int Constitution::HPBonus() const
{
  ConstitutionAbilities con_abi = GetConstitutionAbilities(constitution_);

  return con_abi.hp_bonus;
}

} // namespace battle_system
