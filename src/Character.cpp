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

#include "Character.h"

#include <iostream>

namespace battle_system
{

namespace
{
  int const BASE_AC           =  10;
  int const MIN_AC            = -10;
  int const MAX_LEVEL         =  20;
  float const STATS_BONUS_EXP =  1.10; // 10%;
}

Character::Character(Class::Ptr const& char_class, CharacterStats const& stats, std::string const& name)
  : current_health_(char_class->Health())
  , experience_(0)
  , name_ (name)
  , stats_(stats)
  , class_(char_class)
{
  ArmorInfo a_info = {5};
  ItemInfo  i_info = {75, 40, "Chain Mail", ItemType::ARMOR};
  Armor::Ptr armor = std::make_shared<Armor>(a_info, i_info);
  equipment_.SetItem(armor);

  ShieldInfo s_info = {-1};
  i_info = {15, 10, "Large Shield", ItemType::SHIELD};
  Shield::Ptr shield = std::make_shared<Shield>(s_info, i_info);
  equipment_.SetItem(shield);

  std::string str = std::to_string(stats.strength.GetStrength());
  if (stats.strength.GetStrength() == 18)
    str += "/" + std::to_string(stats.strength.GetPercentStrength());

  std::cout << "Character Created:\n" <<
               "  Class:        " << class_->ClassName() << "\n" <<
               "  Strength:     " << str << "\n" <<
               "  Intelligence: " << stats.intelligence.GetIntelligence() << "\n" <<
               "  Wisdom:       " << stats.wisdom.GetWisdom() << "\n" <<
               "  Dexterity:    " << stats.dexterity.GetDexterity() << "\n" <<
               "  Constitution: " << stats.constitution.GetConstitution() << "\n" <<
               "  Charisma:     " << stats.charisma.GetCharisma() << "\n" <<
               "  Weight:       " << equipment_.Weight() <<
  std::endl;

  AddExperience(experience_);
}

int Character::ArmorClass() const
{
  // BaseAC + Sheild + Dex
  return equipment_.BaseAC() +
         equipment_.ShieldACBonus() +
         stats_.dexterity.ACBonus();
}

int Character::DexterityACBonus() const
{
  return stats_.dexterity.ACBonus();
}

int Character::ShieldACBounus() const
{
  return equipment_.ShieldACBonus();
}

int Character::ToHitBonus() const
{
  return stats_.strength.HitProbBonus();
}

int Character::DamageBonus() const
{
  return stats_.strength.DamageBonus();
}

// TODO Will be from the class selected
int Character::THAC0() const
{
  return class_->THAC0();
}

UnitSize Character::Size() const
{
  return UnitSize::MEDIUM;
}

// Needed for setting up the list of who attacks when
// TODO Will get from equipment
int Character::AttackSpeed() const
{
  return 5;
}

// TODO Will get from class
int Character::NumberOfAttacks(int round) const
{
  // FIXME Need to check if we are using a bow! As most bows give 2/1 ROF
  return class_->NumberOfMeleeAttacks(round);
}

// TODO Will get from class/race
int Character::Health() const
{
  return current_health_;
}

int Character::MaxHealth() const
{
  return class_->Health();
}

int Character::Experience() const
{
  return experience_;
}

void Character::AddExperience(int exp)
{
  if (class_->StatsGrantBonusExperience(stats_))
    exp *= STATS_BONUS_EXP;

  experience_ += exp;

  while (experience_ >= class_->NeededExperienceToLevel() && class_->Level() < MAX_LEVEL)
  {
    std::cout << "LEVEL UP! " << class_->Level() << " to " << class_->Level() + 1 << std::endl;
    class_->LevelUp(stats_);
    current_health_ = MaxHealth();
  }
}

void Character::EquipItem(Item::Ptr const& item)
{
  // TODO Make sure if we remove an item to add it back to my inv!
  equipment_.SetItem(item);
}

Weapon::Ptr Character::UseWeapon()
{
  return equipment_.GetWeapon();
}

void Character::TakeDamage(int damage)
{
  current_health_ -= damage;
  if (current_health_ <= 0)
    std::cout << name_ << " Has died!" << std::endl;
}

std::string Character::Name() const
{
  return name_;
}

} // namespace battle_system
