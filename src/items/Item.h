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

#ifndef ITEM_H
#define ITEM_H

#include <memory>

namespace battle_system
{

enum class ItemType : unsigned
{
  NONE,
  ARMOR,
  HELM,
  BRACERS,
  SHIELD,
  RING,
  AMULET,
  WEAPON,
};

struct ItemInfo
{
  int cost;
  int weight;
  std::string name;
  ItemType    type;
};

class Item
{
public:
  typedef std::shared_ptr<Item> Ptr;

  Item(ItemInfo const& info);
  virtual ~Item() = default;

  int Cost()   const;
  int Weight() const;
  std::string Name() const;
  ItemType    Type() const;

private:
  int cost_;
  int weight_;
  std::string name_;
  ItemType    type_;

};

} // namespace battle_system

#endif // ITEM_H
