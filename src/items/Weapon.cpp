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

#include "Weapon.h"

namespace battle_system
{

Weapon::Weapon(WeaponInfo const& weapon, ItemInfo const& info)
  : Item(info)
  , damage_      (weapon.damage)
  , damage_large_(weapon.damage_large)
  , speed_       (weapon.speed)
{
}

Dice Weapon::Damage() const
{
  return damage_;
}

Dice Weapon::DamageLarge() const
{
  return damage_large_;
}

int Weapon::Speed() const
{
  return speed_;
}

} // namespace battle_system
