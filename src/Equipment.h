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

#ifndef EQUIPMENT
#define EQUIPMENT

#include "items/Armor.h"
#include "items/Shield.h"
#include "items/Weapon.h"

namespace battle_system
{

class Equipment
{
public:
  Equipment();

  int BaseAC() const;
  int ShieldACBonus() const;
  Weapon::Ptr GetWeapon() const;

  int Weight() const;

  Item::Ptr SetItem(Item::Ptr const& Item);
  Item::Ptr RemoveItem(ItemType const& type);

  //void SetArmor(Armor::Ptr const& armor);

private:
  Armor::Ptr  armor_;
  Shield::Ptr shield_;
  Weapon::Ptr weapon_;
};

} // namespace battle_system

#endif // EQUIPMENT
