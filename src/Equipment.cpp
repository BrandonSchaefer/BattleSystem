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

#include "Equipment.h"

namespace battle_system
{

namespace
{
  int const DEFAULT_BASE_AC = 10;
}

Equipment::Equipment()
{
}

int Equipment::BaseAC() const
{
  if (armor_)
    return armor_->BaseAC();

  return DEFAULT_BASE_AC;
}

int Equipment::ShieldACBonus() const
{
  if (shield_)
    return shield_->ShieldBonus();

  return 0;
}

Weapon::Ptr Equipment::GetWeapon() const
{
  return weapon_;
}

// FIXME Make an Empty Item Class soo i dont have to deal with Nullptr
int Equipment::Weight() const
{
  return armor_->Weight() +
         shield_->Weight();
         //weapon_->Weight();
}

Item::Ptr Equipment::SetItem(Item::Ptr const& item)
{
  Item::Ptr removed_item = nullptr;

  switch (item->Type())
  {
    case ItemType::ARMOR:
      removed_item = armor_;
      armor_       = std::static_pointer_cast<Armor>(item);
      break;
    case ItemType::HELM:
    case ItemType::SHIELD:
      removed_item = shield_;
      shield_      = std::static_pointer_cast<Shield>(item);
      break;
    case ItemType::BRACERS:
      break;
    case ItemType::RING:
      break;
    case ItemType::WEAPON:
      removed_item = weapon_;
      weapon_      = std::static_pointer_cast<Weapon>(item);
      break;
    case ItemType::NONE:
    default:
    printf("LKSJDLFKJSDFLK?\n");
      // Found nothing to equipt
      removed_item = item;
      break;
  }

  return removed_item;
}

Item::Ptr Equipment::RemoveItem(ItemType const& type)
{
  Item::Ptr removed_item = nullptr;

  switch (type)
  {
    case ItemType::ARMOR:
      removed_item = armor_;
      armor_       = nullptr;
      break;
    case ItemType::HELM:
      break;
    case ItemType::BRACERS:
      break;
    case ItemType::SHIELD:
      removed_item = shield_;
      shield_      = nullptr;
      break;
    case ItemType::RING:
      break;
    case ItemType::AMULET:
      break;
    case ItemType::WEAPON:
      removed_item = weapon_;
      weapon_      = nullptr;
      break;
    case ItemType::NONE:
    default:
      break;
  }

  return removed_item;
}

} // namespace battle_system
