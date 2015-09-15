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

#ifndef BATTLE_SYSTEM
#define BATTLE_SYSTEM

#include "DiceFactory.h"
#include "Unit.h"
#include "UnitGroup.h"

namespace battle_system
{

class BattleSystem
{
public:
  BattleSystem(DiceFactory const& dice_factory);

  void StartBattle(UnitGroup& group1, UnitGroup& group2);

  void HandleAttack(Unit::Ptr& attacker, Unit::Ptr& defender);

private:
  DiceFactory dice_factory_;
  Dice d20;
  Dice d8;
  Dice init_die;

  int round_;

};

} // namespace battle_system

#endif // BATTLE_SYSTEM
