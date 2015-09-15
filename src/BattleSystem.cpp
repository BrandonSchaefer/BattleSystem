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

#include "BattleSystem.h"

#include <algorithm>
#include <queue>

// FIXME Remove when not needed
#include <stdio.h>
#include <iostream>

namespace battle_system
{

namespace
{
  struct UnitAttackOrder
  {
    int init;
    int attack_num;
    int group;
    Unit::Ptr unit;
  };
}

bool min_init_to_max(UnitAttackOrder const& unit1, UnitAttackOrder const& unit2)
{
  return unit1.init < unit2.init;
}

BattleSystem::BattleSystem(DiceFactory const& dice_factory)
  : dice_factory_(dice_factory)
  , d20(dice_factory_.CreateDice(1, 20))
  , d8(dice_factory_.CreateDice(1, 8))
  , init_die(dice_factory.CreateDice(1, 6))
  , round_(0)
{
}

void BattleSystem::StartBattle(UnitGroup& group1, UnitGroup& group2)
{
  std::vector<UnitAttackOrder> attack_order;

  Unit::Ptr r1;
  Unit::Ptr r2;

  for (auto const& u : group1)
  {
    for (int i = 0; i < u->NumberOfAttacks(round_); i++)
    {
      int init_roll    = init_die.Roll();
      int attack_speed = u->AttackSpeed();
      attack_order.push_back({init_roll + attack_speed + (i * 100), i, 1, u});
    }

    r1 = u;
  }

  for (auto const& u : group2)
  {
    for (int i = 0; i < u->NumberOfAttacks(round_); i++)
    {
      int init_roll    = init_die.Roll();
      int attack_speed = u->AttackSpeed();
      attack_order.push_back({init_roll + attack_speed + (i * 100), i, 2, u});
    }

    r2 = u;
  }

  std::sort(attack_order.begin(), attack_order.end(), min_init_to_max);
/*
  for (auto const& u : attack_order)
  {
    std::cout << "Name: "     << u.unit->Name() <<
                 "  Health: " << u.unit->Health() <<
                 "  Init: "   << u.init  <<
                 "  Group: "  << u.group <<
                 "  Num:  "   << u.attack_num << std::endl;
  }
  */


  for (auto& u : attack_order)
  {
    if (r1 && r2)
    {
      if (u.group == 1)
        HandleAttack(u.unit, r2);
      else
        HandleAttack(u.unit, r1);

      if (u.unit->Health() <= 0)
      {
        if (u.group == 1)
          group1.RemoveUnit(u.unit);
        else
          group2.RemoveUnit(u.unit);
      }
      else if (r1->Health() <= 0)
      {
        group1.RemoveUnit(r1);
        if (!group1.Empty())
          r1 = *group1.begin();
        else
          r1 = nullptr;
      }
      else if (r2->Health() <= 0)
      {
        group2.RemoveUnit(r2);
        if (!group2.Empty())
          r2 = *group2.begin();
        else
          r2 = nullptr;
      }
    }
  }

  for (auto const& u : group1)
  {
    std::cout << "Name: "     << u->Name() <<
                 "  Health: " << u->Health() <<
    std::endl;
  }

  for (auto const& u : group2)
  {
    std::cout << "Name: "     << u->Name() <<
                 "  Health: " << u->Health() <<
    std::endl;
  }

  round_++;
}

void BattleSystem::HandleAttack(Unit::Ptr& attacker, Unit::Ptr& defender)
{
  int to_hit_modifiers = attacker->ToHitBonus();
  // TODO Check if we are flanking/rear attacking or if the defender has a status
  // such that our to_hit_modifier is increased
  int attempt_hit = d20.Roll(to_hit_modifiers);

  Weapon::Ptr weapon = attacker->UseWeapon();
  Dice weapon_damage = defender->Size() > UnitSize::LARGE ? weapon->DamageLarge() : weapon->Damage();
  int defender_AC    = defender->ArmorClass();
  int need_to_hit    = attacker->THAC0() - defender_AC;

  // TODO Figure out how to get the current attack the attacker is using.
  printf("Unit: %s Attacks with %s against %s with attack roll: %i and needs: %i\n", attacker->Name().c_str(), weapon->Name().c_str(), defender->Name().c_str(), attempt_hit, need_to_hit);
  if (attempt_hit == 1)
  {
    // TODO Add maybe something special here, critical fail
  }
  else if (attempt_hit == 20)
  {
    // Max damage
    int damage_mod     = attacker->DamageBonus();
    int damage = weapon_damage.Roll(damage_mod) + weapon_damage.Roll();

    std::cout << "Critical Hit! Double Damage: " << weapon_damage.Rolls() * 2 << "d" << weapon_damage.Die() << " + " << damage_mod << " Hitting for: " << damage << std::endl;

    defender->TakeDamage(damage);
  }
  else if (attempt_hit >= need_to_hit)
  {
    /*
    Weapon::Ptr weapon = attacker->UseWeapon();
    if (defender->Size() >= UnitSize::LARGE)
      weapon = attacker->DamageLarge();
    else
      damage = attacker->Damage();
    */

    int damage_mod     = attacker->DamageBonus();
    int damage         = weapon_damage.Roll(damage_mod);

    std::cout << "Hit: " << weapon_damage.Rolls() << "d" << weapon_damage.Die() << " + " << damage_mod << " Hitting for: " << damage << std::endl;
    defender->TakeDamage(damage);
  }
}

} // namespace battle_system
