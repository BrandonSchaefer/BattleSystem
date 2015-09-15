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

#include "Monster.h"

#include <memory>

#include <stdio.h>

namespace battle_system
{

namespace
{
  // TINY, SMALL, MEDIUM, LARGE, GAINT, GARGAUTUM
  int const MONSTER_ATTACK_SPEED[] = {0, 3, 3, 6, 9, 12};

  int const MONSTER_THAC0[]        = {
                                       20, // 1 - n
                                       19, // 1
                                       18, // 1+
                                       16, // 2+
                                       16, // 3+
                                       15, // 4+
                                       15, // 5+
                                       13, // 6+
                                       13, // 7+
                                       12, // 8+
                                       12, // 9+
                                       10, // 10+
                                       10, // 11+
                                        9, // 12+
                                        9, // 13+
                                        8, // 14+
                                        8, // 15+
                                        7  // 16+
                                     };

  int const THAC0_MAX              = 17;
  int const PLUS_ABOVE_THREE       =  3;
}

Monster::Monster(MonsterBreed& breed)
  : health_     (breed.hit_die.Roll())
  , max_health_ (health_)
  , armor_class_(breed.armor_class)
  , size_       (breed.size)
  , name_       (breed.name)
  , hit_die_    (breed.hit_die)
  , current_attack_(0)
  , attacks_    (breed.attacks)
{
}

int Monster::ArmorClass() const
{
  return armor_class_;
}

int Monster::DexterityACBonus() const
{
  return 0;
}

int Monster::ShieldACBounus() const
{
  return 0;
}

int Monster::ToHitBonus() const
{
  return 0;
}

int Monster::DamageBonus() const
{
  return 0;
}

int Monster::THAC0() const
{
  int hit_die = hit_die_.Rolls();
  int mod     = hit_die_.Mod();
  int index   = hit_die + 1;

  if (mod >= 3)
    index++;

  if (hit_die == 1 && mod < 0)
    index = 0;
  else if (hit_die == 1 && mod == 0)
    index = 1;

  index = std::min(THAC0_MAX, index);

  return MONSTER_THAC0[index];
}

UnitSize Monster::Size() const
{
  return size_;
}

int Monster::AttackSpeed() const
{
  return MONSTER_ATTACK_SPEED[size_];
}

int Monster::NumberOfAttacks(int round) const
{
  return attacks_.size();
}

int Monster::Health() const
{
  return health_;
}

int Monster::Experience() const
{
  return 0;
}

// FIXME Need to wait until i finish how monsters are generated...then return the actual max
int Monster::MaxHealth() const
{
  return max_health_;
}

// TODO Do we want some monsters to gain exp?
void Monster::AddExperience(int exp)
{
}

void Monster::TakeDamage(int damage)
{
  health_ -= damage;

  if (health_ <= 0)
    printf("%s is dead!\n", name_.c_str());
}

// FIXME Should i do something here?
void Monster::EquipItem(Item::Ptr const& item)
{
}

Weapon::Ptr Monster::UseWeapon()
{
  Weapon::Ptr attack = attacks_[current_attack_];
  current_attack_    = (current_attack_ + 1) % attacks_.size();

  return attack;
}

std::string Monster::Name() const
{
  return name_;
}

} // namespace battle_system
