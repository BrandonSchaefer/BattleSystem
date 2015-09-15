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

#include "Item.h"

namespace battle_system
{

Item::Item(ItemInfo const& info)
  : cost_  (info.cost)
  , weight_(info.weight)
  , name_  (info.name)
  , type_  (info.type)
{
}

int Item::Cost() const
{
  return cost_;
}

int Item::Weight() const
{
  return weight_;
}

std::string Item::Name() const
{
  return name_;
}

ItemType Item::Type() const
{
  return type_;
}

} // namespace battle_system
