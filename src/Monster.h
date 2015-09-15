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

#ifndef MONSTER
#define MONSTER

#include "Dice.h"
#include "Unit.h"

namespace battle_system
{

struct MonsterBreed
{
  Dice hit_die;
  int  armor_class;
  UnitSize    size;
  std::string name;
  std::vector<Weapon::Ptr> attacks;
};


class Monster : public Unit
{
public:
  Monster(MonsterBreed& breed);

  virtual int ArmorClass()       const override;
  virtual int DexterityACBonus() const override;
  virtual int ShieldACBounus()   const override;
  virtual int ToHitBonus()       const override;
  virtual int DamageBonus()      const override;
  virtual int THAC0()            const override;

  virtual UnitSize Size() const override;

  virtual int AttackSpeed()     const override;
  virtual int NumberOfAttacks(int round) const override;

  virtual int Health()     const override;
  virtual int MaxHealth()  const override;
  virtual int Experience() const override;

  virtual void AddExperience(int exp) override;
  virtual void TakeDamage(int damage) override;

  virtual void EquipItem(Item::Ptr const& item) override;
  virtual Weapon::Ptr UseWeapon() override;

  virtual std::string Name() const override;

private:
  int health_;
  int max_health_;
  int armor_class_;
  UnitSize    size_;
  std::string name_;
  Dice hit_die_;

  int current_attack_;
  std::vector<Weapon::Ptr> attacks_;
};

} // namespace battle_system

#endif // MONSTER
