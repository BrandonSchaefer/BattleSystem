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

#ifndef FIGHTER
#define FIGHTER

#include "CharacterStats.h"
#include "Class.h"

namespace battle_system
{

class Fighter : public Class
{
public:
  Fighter(Dice const& hit_dice);
  virtual int NumberOfMeleeAttacks(int round = 0) const override;
  virtual int THAC0() const override;
  virtual int SavingThrow(SavingThrowType const& type) const override;

  virtual bool     StatsGrantBonusExperience(CharacterStats const& stats) const override;
  virtual unsigned NeededExperienceToLevel()   override;

private:
  virtual std::string ClassName() const override;

  virtual int ConstitutionHPBonus(CharacterStats const& stats) const override;
  virtual int MaxHitDiceLevel()            const override;
  virtual int ConstLifeAfterMaxDiceLevel() const override;
};

} // namespace battle_system

#endif // FIGHTER
