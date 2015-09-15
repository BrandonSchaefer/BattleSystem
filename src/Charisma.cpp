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

#include "Charisma.h"

namespace battle_system
{

namespace
{
  int const MIN_CHA =  3;
  int const MAX_CHA = 18;

  struct CharismaAbilities
  {
    int reaction_bonus;
  };

  static CharismaAbilities const charisma_abilities[] = {
                                                          {-5}, //3
                                                          {-4}, //4
                                                          {-3}, //5
                                                          {-2}, //6
                                                          {-1}, //7
                                                          { 0}, //8
                                                          { 0}, //9
                                                          { 0}, //10
                                                          { 0}, //11
                                                          { 0}, //12
                                                          { 1}, //13
                                                          { 2}, //14
                                                          { 3}, //15
                                                          { 5}, //16
                                                          { 6}, //17
                                                          { 7}, //18
                                                        };
}

static CharismaAbilities GetCharismaAbilities(int charisma)
{
  if (charisma >= MIN_CHA && charisma <= MAX_CHA)
    return charisma_abilities[charisma - MIN_CHA];

  return {0};
}

Charisma::Charisma(int charisma)
  : charisma_(charisma)
{
}

int Charisma::GetCharisma() const
{
  return charisma_;
}

void Charisma::SetCharisma(int charisma)
{
  charisma_ = charisma;
}

int Charisma::ReactionBonus() const
{
  CharismaAbilities cha_abi = GetCharismaAbilities(charisma_);

  return cha_abi.reaction_bonus;
}

} // namespace battle_system
