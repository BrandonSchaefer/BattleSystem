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

#ifndef UNIT
#define UNIT

#include <string>
#include <memory>

#include "items/Weapon.h"

namespace battle_system
{

enum UnitSize
{
  TINY = 0,
  SMALL,
  MEDIUM,
  LARGE,
  GAINT,
  GARGANTUAN,
};

class Unit
{
public:
  typedef std::shared_ptr<Unit> Ptr;

  Unit() = default;

  // Need souly for the actual attempted attack
  virtual int ArmorClass()       const = 0;
  virtual int DexterityACBonus() const = 0;
  virtual int ShieldACBounus()   const = 0;
  virtual int ToHitBonus()       const = 0;
  virtual int DamageBonus()      const = 0;
  virtual int THAC0()            const = 0;

  virtual UnitSize Size() const = 0;

  // Needed for setting up the list of who attacks when
  virtual int AttackSpeed()     const = 0;
  virtual int NumberOfAttacks(int round = 0) const = 0;

  virtual int Health()     const = 0;
  virtual int MaxHealth()  const = 0;
  virtual int Experience() const = 0;

  virtual void AddExperience(int exp) = 0;
  virtual void TakeDamage(int damage) = 0;

  virtual void EquipItem(Item::Ptr const& item) = 0;
  virtual Weapon::Ptr UseWeapon() = 0;

  virtual std::string Name() const = 0;

  // TODO add a signal to emit when the monster dies

private:
};

} // namespace battle_system

#endif // UNIT
