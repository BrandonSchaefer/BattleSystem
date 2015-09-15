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

#ifndef WEAPON_H
#define WEAPON_H

#include "Dice.h"
#include "Item.h"

namespace battle_system
{

struct WeaponInfo
{
  Dice damage;
  Dice damage_large;
  int speed;
};

class Weapon : public Item
{
public:
  typedef std::shared_ptr<Weapon> Ptr;

  Weapon(WeaponInfo const& weapon, ItemInfo const& info);

  Dice Damage()      const;
  Dice DamageLarge() const;
  int  Speed()       const;

private:
  Dice damage_;
  Dice damage_large_;
  int  speed_;
};

} // namespace battle_system

#endif // WEAPON_H
