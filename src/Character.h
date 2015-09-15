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

#ifndef CHARACTER
#define CHARACTER

#include "CharacterStats.h"
#include "Class.h"
#include "Equipment.h"
#include "Unit.h"

namespace battle_system
{

class Character : public Unit
{
public:
  Character(Class::Ptr const& char_class, CharacterStats const& stats, std::string const& name);

  virtual int ArmorClass()       const override;
  virtual int DexterityACBonus() const override;
  virtual int ShieldACBounus()   const override;
  virtual int ToHitBonus()       const override;
  virtual int DamageBonus()      const override;
  virtual int THAC0()            const override;

  virtual UnitSize Size() const override;

  // Needed for setting up the list of who attacks when
  virtual int AttackSpeed()     const override;
  virtual int NumberOfAttacks(int round = 0) const override;

  virtual int Health()     const override;
  virtual int MaxHealth()  const override;
  virtual int Experience() const override;

  virtual void AddExperience(int exp) override;
  virtual void TakeDamage(int damage) override;

  virtual std::string Name() const override;

  virtual void EquipItem(Item::Ptr const& item) override;
  virtual Weapon::Ptr UseWeapon() override;

private:
  int current_health_;
  unsigned experience_;
  
  std::string name_;

  CharacterStats stats_;
  Class::Ptr class_;

  Equipment equipment_;
};

} // namespace battle_system

#endif // CHARACTER
