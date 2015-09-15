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

#include "Fighter.h"

#include <iostream>

namespace battle_system
{

namespace
{
  int const STR_EXP_BONUS         = 16;
  int const START_THAC0           = 20;
  int const MAX_HIT_DICE_LEVEL    =  9;
  int const CONST_LIFE_GAINED     =  3;

  int const MAX_SAVING_THROW_INDEX = 8;

  std::string CLASS_NAME          = "Fighter";
  unsigned const FIGHTER_LEVELS[] = {
                                            0, // 1
                                         2000, // 2
                                         4000, // 3
                                         8000, // 4
                                        16000, // 5
                                        32000, // 6
                                        64000, // 7
                                       125000, // 8
                                       250000, // 9
                                       500000, // 10
                                       750000, // 11
                                      1000000, // 12
                                      1250000, // 13
                                      1500000, // 14
                                      1750000, // 15
                                      2000000, // 16
                                      2250000, // 17
                                      2500000, // 18
                                      2750000, // 19
                                      3000000  // 20
                                    };

  // Warrior saving throws, will be using by paladin/ranger
  int const PARA_POISON_DEATH_MATRIX[] = {14, 13, 11, 10, 8,  7,  5, 4, 3};
  int const PETRI_POLY_MATRIX[]        = {15, 14, 12, 11, 9,  8,  6, 5, 4};
  int const ROD_STAFF_WAND_MATRIX[]    = {16, 15, 13, 12, 10, 9,  7, 6, 5};
  int const BREATH_MATRIX[]            = {17, 16, 13, 12, 9,  8,  5, 4, 4};
  int const SPELL_MATRIX[]             = {17, 16, 14, 13, 11, 10, 8, 7, 6};
}

Fighter::Fighter(Dice const& dice)
  : Class(dice)
{
}

int Fighter::NumberOfMeleeAttacks(int round) const
{
  // 1: Level 1-6  = 1  /round
  // 2: Level 6-12 = 1.5/round
  // 3: Level 13+  = 2  /round

  if (level_ <= 6)
    return 1;
  else if (level_ >= 13)
    return 2;

  // When round is even return 2, otherwise return 1
  if (round % 2 == 0)
    return 2;

  return 1;
}

bool Fighter::StatsGrantBonusExperience(CharacterStats const& stats) const
{
  return stats.strength.GetStrength() >= STR_EXP_BONUS;
}

int Fighter::THAC0() const
{
  return START_THAC0 - level_ + 1;
}

int Fighter::SavingThrow(SavingThrowType const& type) const
{
  int index = std::min((level_ - 1) / 2, MAX_SAVING_THROW_INDEX);

  switch (type)
  {
    case SavingThrowType::PARA_POISON_DEATH:
      return PARA_POISON_DEATH_MATRIX[index];
    case SavingThrowType::PETRI_POLY:
      return PETRI_POLY_MATRIX[index];
    case SavingThrowType::ROD_STAFF_WAND:
      return ROD_STAFF_WAND_MATRIX[index];
    case SavingThrowType::BREATH:
      return BREATH_MATRIX[index];
    case SavingThrowType::SPELL:
      return SPELL_MATRIX[index];
  }

  return 0;
}

int Fighter::ConstitutionHPBonus(CharacterStats const& stats) const
{
  return stats.constitution.HPBonus();
}

int Fighter::MaxHitDiceLevel() const
{
  return MAX_HIT_DICE_LEVEL;
}

int Fighter::ConstLifeAfterMaxDiceLevel() const
{
  return CONST_LIFE_GAINED;
}

unsigned Fighter::NeededExperienceToLevel()
{
  return FIGHTER_LEVELS[level_];
}

std::string Fighter::ClassName() const
{
  return CLASS_NAME;
}

} // namespace battle_system
