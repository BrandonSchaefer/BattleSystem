// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2014 Brandon Schaefer
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
#include "CharacterStats.h"

#include "BattleSystem.h"
#include "DiceFactory.h"
#include "Monster.h"
#include "items/Weapon.h"

#include "Fighter.h"

#include "Human.h"

#include "UnitGroup.h"

#include "MoneyPouch.h"

#include <iostream>
#include <algorithm>
#include <vector>

namespace bs = battle_system;

int GetHighestRoll(bs::Dice& d)
{
  int max = 0;
  for (int i = 0; i < 6; i++)
  {
    int roll = d.Roll();
    if (roll > max)
      max = roll;
  }

  return max;
}

bool max_to_min(int i, int j)
{
  return i > j;
}

// Method 1
int Roll4d6GetBest3(bs::Dice& d)
{
  std::vector<int> rolls;
  for (int i = 0; i < 4; i++)
    rolls.push_back(d.Roll());

  std::sort(rolls.begin(), rolls.end(), max_to_min);

  return std::accumulate(rolls.begin(), rolls.begin() + 3, 0);
}

// Using Method 3 to creating characters:
// Roll 3d6 6 times in the order of STR, INT, WIS, DEX, CON, CHA
// Pick the highest for the roll

void print_class(bs::Class::Ptr const& ptr)
{
  std::cout << "Class: "   << ptr->ClassName()  << std::endl <<
               " Level: "  << ptr->Level()      << std::endl <<
               " Health: " << ptr->Health()      << std::endl <<
               " THAC0: "  << ptr->THAC0()      << std::endl <<

               " PPD: "  << ptr->SavingThrow(bs::SavingThrowType::PARA_POISON_DEATH) << std::endl <<
               " RSW: "  << ptr->SavingThrow(bs::SavingThrowType::ROD_STAFF_WAND)    << std::endl <<
               " PP: "   << ptr->SavingThrow(bs::SavingThrowType::PETRI_POLY)        << std::endl <<
               " B: "    << ptr->SavingThrow(bs::SavingThrowType::BREATH)            << std::endl <<
               " S: "    << ptr->SavingThrow(bs::SavingThrowType::SPELL)             << std::endl <<

               " # Atck: " << ptr->NumberOfMeleeAttacks(2) <<
  std::endl;
}

void print_unit(bs::Unit::Ptr const& u)
{
  std::cout << "Unit            " << u->Name() << "\n"
            << " AC:            " << u->ArmorClass() << "\n"
            << " DexACBonus:    " << u->DexterityACBonus() << "\n"
            << " ShieldACBonus: " << u->ShieldACBounus() << "\n"
            << " ToHitBonus:    " << u->ToHitBonus() << "\n"
            << " DamageBonus:   " << u->DamageBonus() << "\n"
            << " THAC0:         " << u->THAC0() << "\n"
            << " Size:          " << u->Size() << "\n"
            << " AttackSpeed:   " << u->AttackSpeed() << "\n"
            << " #OfAttacks:    " << u->NumberOfAttacks() << "\n"
            << " Health:        " << u->Health()
  << std::endl;
}

int main()
{
  srand(time(nullptr));
  bs::DiceFactory df;

  bs::BattleSystem battle_system(df);
  //while (m1->Health() > 0 && m2->Health() > 0)
  //{
    //battle_system.HandleAttack(m1, m2);
    //battle_system.HandleAttack(m2, m1);
    //std::cout << "Monster1: " << m1->Health() << " Monster2: " << m2->Health() << std::endl;
  //}

  bs::Dice stats_3d6 = df.CreateDice(3, 6);

  //for (int i = 0; i < 6; i++)
    //std::cout << Roll4d6GetBest3(d6) << std::endl;

  //std::vector<int> rolls

  //for (int i = 0; i < 4; i++)
    //std::cout << d.Roll() << " ";
  //std::cout << std::endl;

  bs::CharacterStats stats1 = {
                                bs::Strength    (GetHighestRoll(stats_3d6)),
                                bs::Intelligence(GetHighestRoll(stats_3d6)),
                                bs::Wisdom      (GetHighestRoll(stats_3d6)),
                                bs::Dexterity   (GetHighestRoll(stats_3d6)),
                                bs::Constitution(GetHighestRoll(stats_3d6)),
                                bs::Charisma    (GetHighestRoll(stats_3d6))
                             };

  bs::CharacterStats stats2 = {
                                bs::Strength    (GetHighestRoll(stats_3d6)),
                                bs::Intelligence(GetHighestRoll(stats_3d6)),
                                bs::Wisdom      (GetHighestRoll(stats_3d6)),
                                bs::Dexterity   (GetHighestRoll(stats_3d6)),
                                bs::Constitution(GetHighestRoll(stats_3d6)),
                                bs::Charisma    (GetHighestRoll(stats_3d6))
                             };

  bs::Dice percent_roll = df.CreateDice(1, 100);
  if (stats1.strength.GetStrength() == 18)
    stats1.strength.SetPercentStrength(percent_roll.Roll());

  if (stats2.strength.GetStrength() == 18)
    stats2.strength.SetPercentStrength(percent_roll.Roll());

  bs::Dice hit_die_fighter = df.CreateDice(1, 10);
  bs::Class::Ptr fighter1  = std::make_shared<bs::Fighter>(hit_die_fighter);
  bs::Class::Ptr fighter2  = std::make_shared<bs::Fighter>(hit_die_fighter);

  bs::Unit::Ptr c1 = std::make_shared<bs::Character>(fighter1, stats1, "Fighter1");
  bs::Unit::Ptr c2 = std::make_shared<bs::Character>(fighter2, stats2, "Fighter2");

  c1->AddExperience(4000);
  c2->AddExperience(4000);

  bs::WeaponInfo  long_info = {df.CreateDice(1, 8), df.CreateDice(1, 12), 5};
  bs::ItemInfo    long_item_info = {65, 4, "Long Sword", bs::ItemType::WEAPON};
  bs::Weapon::Ptr long_sword = std::make_shared<bs::Weapon>(long_info, long_item_info);

  std::cout << "Weapon: "        << long_sword->Name()  <<
               "\nCost: "        << long_sword->Cost()  <<
               "\nSpeed: "       << long_sword->Speed() <<
               "\nDamage: "      << long_sword->Damage().Roll() << 
               "\nDamageLarge: " << long_sword->DamageLarge().Roll() << std::endl;

  printf("lkajdslkfalkdsjfds?\n");
  c1->EquipItem(long_sword);
  c2->EquipItem(long_sword);

  std::cout << c1->Health() << " " << c2->Health() << std::endl;

  //while (c1->Health() > 0 && m1->Health() > 0)
  {
    //battle_system.HandleAttack(c1, m1);
    //battle_system.HandleAttack(c2, c1);
    //battle_system.HandleAttack(m1, c1);
    //std::cout << "Character1: " << c1->Health() << " Character2: " << m1->Health() << std::endl;
  }

  print_class(fighter1);
  print_class(fighter2);

  bs::Race::Ptr human = std::make_shared<bs::Human>(df);
  std::cout << "Race: "    << human->RaceName() << std::endl <<
               " BaseMove: " << human->BaseMove() << std::endl <<
               " Age: "      << human->Age() << std::endl <<
               " Weight: "   << human->Weight()   << std::endl <<
               " Height: "   << human->Height() / 12 << "'" << human->Height() % 12 << "\"" <<
  std::endl;

  bs::UnitGroup chars, mons;

  bs::WeaponInfo c_info = {df.CreateDice(1, 6), df.CreateDice(1, 6), 0};
  bs::ItemInfo c_i_info = {0, 0, "Claw", bs::ItemType::WEAPON};
  bs::Weapon::Ptr claw  = std::make_shared<bs::Weapon>(c_info, c_i_info);

  bs::WeaponInfo b_info = {df.CreateDice(1, 8), df.CreateDice(1, 8), 0};
  bs::ItemInfo b_i_info = {0, 0, "Beak", bs::ItemType::WEAPON};
  bs::Weapon::Ptr beak  = std::make_shared<bs::Weapon>(b_info, b_i_info);

  bs::Dice m_hit_die = df.CreateDice(2, 8);
  bs::Unit::Ptr m;
  for (int i = 0; i < 8; i++)
  {
    //std::cout << "..." << m_hit_die.Roll() << std::endl;
    bs::MonsterBreed b = {m_hit_die, 8, bs::UnitSize::MEDIUM, "Clubnek" + std::to_string(i), {claw, claw, beak}};
    m = std::make_shared<bs::Monster>(b);
    mons.AddUnit(m);
  }

  print_unit(m);

  chars.AddUnit(c1);
  chars.AddUnit(c2);

  while (!mons.Empty() && !chars.Empty())
  {
    battle_system.StartBattle(chars, mons);
  }

  //std::cout << "UnitGroup Size: " << chars.Size() << std::endl;

  //for (auto& u : chars)
  {
    //std::cout << u->Health() << std::endl;
    //chars.RemoveUnit(it++);
  }

  //std::cout << "UnitGroup Size: " << chars.Size() << std::endl;

  //for (int i = 0; i < 6; i++)
    //std::cout << GetHighestRoll(d) << std::endl;

  /*
  int test[15] = {0};
  for (int i = 0; i < 100000; i++)
    test[d.Roll() - 3]++;

  for (int i = 0; i <= 15; i++)
    std::cout << test[i] << " ";

  std::cout << std::endl;
  */

  bs::MoneyPouch mp;

  mp.AddMoney(100, bs::MoneyType::GOLD);
  std::cout << "Withdrawn: " << mp.WithdrawMoney(150, bs::MoneyType::GOLD) << std::endl;

  mp.AddMoney(4, bs::MoneyType::GOLD);
  std::cout << "Withdrawn: " << mp.WithdrawMoney(2, bs::MoneyType::GOLD) << std::endl;

  std::cout << "Copper:   " << mp.CheckBalance(bs::MoneyType::COPPER)   << "\n"
            << "Silver:   " << mp.CheckBalance(bs::MoneyType::SILVER)   << "\n"
            << "Electrum: " << mp.CheckBalance(bs::MoneyType::ELECTRUM) << "\n"
            << "Gold:     " << mp.CheckBalance(bs::MoneyType::GOLD)     << "\n"
            << "Platinum: " << mp.CheckBalance(bs::MoneyType::PLATINUM) <<
  std::endl;

  return 0;
}
