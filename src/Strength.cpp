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

#include "Strength.h"

namespace battle_system
{

namespace
{
  int const MAX_STR   = 18;
  int const START_STR = 3;

  struct StrengthAbilities
  {
    int hit_prob;
    int damage;
    int weight;
  };

  // Add more from 2e PHB
  static StrengthAbilities const strength_abilities[] = {
                                                         {-3, -1, 5 },  // 3
                                                         {-2, -1, 10},  // 4
                                                         {-2, -1, 10},  // 5
                                                         {-1,  0, 20},  // 6
                                                         {-1,  0, 20},  // 7
                                                         { 0,  0, 35},  // 8
                                                         { 0,  0, 35},  // 9
                                                         { 0,  0, 40},  // 10
                                                         { 0,  0, 40},  // 11
                                                         { 0,  0, 45},  // 12
                                                         { 0,  0, 45},  // 13
                                                         { 0,  0, 55},  // 14
                                                         { 0,  0, 55},  // 15
                                                         { 0,  1, 70},  // 16
                                                         { 1,  1, 85},  // 17
                                                         { 1,  2, 110}  // 18
                                                      };

  static StrengthAbilities exceptional_strength[] = {
                                                     {1,  3, 135}, // 18/01-50
                                                     {2,  3, 160}, // 18/51-75
                                                     {2,  4, 185}, // 18/76-90
                                                     {2,  5, 235}, // 18/91-99
                                                     {3,  6, 335}  // 18/00
                                                   };
}

static StrengthAbilities GetStrengthAbilities(int strength, int percent_str)
{
  if (percent_str > 0)
  {
    if (percent_str <= 50)
      return exceptional_strength[0];
    else if (percent_str <= 75)
      return exceptional_strength[1];
    else if (percent_str <= 90)
      return exceptional_strength[2];
    else if (percent_str <= 99)
      return exceptional_strength[3];
    else
      return exceptional_strength[4];
  }
  else if (strength >= START_STR && strength <= MAX_STR)
  {
    return strength_abilities[strength - START_STR];
  }

  return {0, 0, 0};
}

Strength::Strength(int strength, int percent_str)
  : strength_(strength)
  , percent_str_(percent_str)
{
}

int Strength::GetStrength() const
{
  return strength_;
}

void Strength::SetStrength(int strength)
{
  strength_ = strength;
}

int Strength::GetPercentStrength() const
{
  return percent_str_;
}

void Strength::SetPercentStrength(int percent_str)
{
  percent_str_ = percent_str;
}

int Strength::HitProbBonus() const
{
  StrengthAbilities str_abi = GetStrengthAbilities(strength_, percent_str_);

  return str_abi.hit_prob;
}

int Strength::DamageBonus() const
{
  StrengthAbilities str_abi = GetStrengthAbilities(strength_, percent_str_);

  return str_abi.damage;
}

int Strength::WeightBonus() const
{
  StrengthAbilities str_abi = GetStrengthAbilities(strength_, percent_str_);

  return str_abi.weight;
}

} // namespace battle_system
