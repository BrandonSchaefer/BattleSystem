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

#ifndef CLASS
#define CLASS

#include "Dice.h"
#include "CharacterStats.h"

#include <memory>

namespace battle_system
{

enum class SavingThrowType : unsigned
{
  PARA_POISON_DEATH,
  PETRI_POLY,
  ROD_STAFF_WAND,
  BREATH,
  SPELL
};

class Class
{
public:
  typedef std::shared_ptr<Class> Ptr;

  Class(Dice const& hit_dice);

  void AddExperience(int experience);

  int Experience() const;
  int Health()     const;
  int Level()      const;

  virtual std::string ClassName() const = 0;
  virtual int NumberOfMeleeAttacks(int round = 0) const = 0;
  virtual int THAC0() const = 0;
  
  virtual int SavingThrow(SavingThrowType const& type) const = 0;

  virtual bool StatsGrantBonusExperience(CharacterStats const& stats) const = 0;
  virtual unsigned NeededExperienceToLevel() = 0;

  void LevelUp(CharacterStats const& stats);

protected:
  int health_;
  int level_;

  Dice hit_dice_;

private:
  virtual int ConstitutionHPBonus(CharacterStats const& stats) const = 0;
  virtual int MaxHitDiceLevel()            const = 0;
  virtual int ConstLifeAfterMaxDiceLevel() const = 0;
};

} // namespace battle_system

#endif // CLASS
